#ifndef SERVER_H_
#define SERVER_H_
#include "Common.h"

using namespace std;
class Server
{
public:
	Server();
	void Init();
	void Start();
	void Close();
private:
	int SendBroadcastMessage(int clientfd);
	struct sockaddr_in serverAddr;
	int listener;
	int epfd;
	list<int> clients_list;
};
#endif
