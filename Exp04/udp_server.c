#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>

int main(int argc,char* argv[])
{
	struct sockaddr_in server,client;
	if (argc != 2)
		printf("Input Format not correct\n");

	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if (sockfd == -1)
		printf("Error in Socket\n");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
		printf("Error in Binding\n");

	char buffer[100];
	socklen_t server_len = sizeof(server);
		printf("Server Waiting....\n");
	if(recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&server_len) < 0)
		printf("Error in recvfrom()\n");
	printf("Got a Datagram : %s",buffer);
	return 0;
}
