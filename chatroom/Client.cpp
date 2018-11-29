#include <iostream>
#include "Client.h"

using namespace std;

Client::Client()
{

	serverAddr.sin_family = PF_INET;
	serverAddr.sin_port = htons(HOST_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(HOST_IP);
	sock = 0;
	pid = 0;
	isClientwork = true;
	epfd = 0;
}

void Client::Connect()
{
	sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("sock error");
		exit(-1);
	}

	if(connect(sock,(struct sockaddr *)&serverAddr,sizeof(serverAddr)) < 0)
	{
		perror("connect error");
		exit(-1);
	}

	if(pipe(pipe_fd) < 0)
	{
		perror("pipe error");
		exit(-1);
	}

	epfd = epoll_create(EPOLL_SIZE);
	if(epfd < 0)
	{
		perror("epfd error");
		exit(-1);
	}
	addfd(epfd, sock ,true);
	addfd(epfd, pipe_fd[0],true);
}

void Client::Close()
{
	if(pid)
	{
		close(pipe_fd[0]);
		close(sock);
	}
	else
	{
		close(pipe_fd[1]);
	}
}

void Client::Start()
{
	static struct epoll_event events[2];
	Connect();
	pid = fork();
	if(pid<0)
	{
		perror("fork error");
		close(sock);
		exit(-1);
	}
	else if(pid == 0)
	{ //child
		close(pipe_fd[0]); //close read pipe
		cout << "'exit' to exit" << endl;
		while(isClientwork)
		{
			bzero(&message,BUF_SIZE);
			fgets(message,BUF_SIZE,stdin);

			if(strncasecmp(message,"exit",strlen("exit")) == 0)
			{
				isClientwork = false;
			}
			else
			{
				if(write(pipe_fd[1],message,strlen(message) -1) < 0)
				{
					perror("write error");
					exit(-1);
				}
			}
		}
	} else {
		//parent
		close(pipe_fd[1]); //close write pipe
		while(isClientwork)
		{
			int epoll_events_count = epoll_wait(epfd,events,2,-1);
			for(int i = 0; i < epoll_events_count ; ++i)
			{
				bzero(&message, BUF_SIZE);
				if(events[i].data.fd == sock)
				{
					int ret = recv(sock, message, BUF_SIZE, 0);
					if(ret == 0)
					{
						cout << "Server closed connection: " << sock << endl;
						close(sock);
						isClientwork = false;
					} else {
						cout << message << endl;
					}
				} else {
					int ret = read(events[i].data.fd, message, BUF_SIZE);
					if(ret == 0)
						isClientwork = false;
					else
						send(sock, message, BUF_SIZE, 0);
				}
			}
		}
	}

	Close();
}
