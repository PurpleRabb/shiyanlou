#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

#define HOST_IP "127.0.0.1"
#define HOST_PORT 9001
#define BUF_SIZE 1024
#define WELCOM "Welcom to chatroom!!!"
#define WELCOME_MESSAGE "Welcom %d to chatroom!!!"
#define GOODBYE "GOODBYE!!!"
#define SERVER_MESSAGE "ClientID %d say >> %s"
#define EPOLL_SIZE 5000

void setnonblocking(int fd)
{
	fcntl(fd, F_SETFL,fcntl(fd,F_GETFD,0) | O_NONBLOCK);
}

void addfd(int epollfd, int fd, bool enable_et)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(enable_et)
		ev.events = EPOLLIN|EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
	setnonblocking(fd);
	printf("fd added to epoll!\n");
}

#endif
