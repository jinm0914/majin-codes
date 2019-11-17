#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#include <fstream>
#define BACKLOG 10

using namespace std;
std::ofstream outfile;

int main(int argc,char *argv[]) {
        //outfile.open ("testData.txt");
	int servefd;
    struct sockaddr_in servaddr;

    servefd = socket(PF_INET, SOCK_DGRAM, 0);

    socklen_t addrlen = sizeof(servaddr);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6981);
    bind(servefd, (struct sockaddr *)&servaddr, sizeof(servaddr));



    std::cout << "t server" << std::endl;
    const char* ip ="192.168.253.10";  //htonl(INADDR_ANY);

    int clientfd;
    clientfd = socket(PF_INET,SOCK_DGRAM , 0);
    if(0 >=clientfd){
            perror(" socket(PF_INET,SOCK_DGRAM , 0)** Failed:"); 
            exit(1);
    }
    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_port = htons(6980);
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);

    char recvbuf[1024] = {0};
    char ints[10]= {0};
    char intus[6]= {0};
    char intcount[5]={0};

	while (1){   
        memset(recvbuf,0,sizeof(recvbuf));        
		int lenrecv = recvfrom(servefd, recvbuf,sizeof(recvbuf), 0, (struct sockaddr *)&servaddr, &addrlen);

        for(int i =21;i<1023;i++)recvbuf[i]='s';
        recvbuf[1024] = '\0';

        int lensend = sendto(clientfd, recvbuf, sizeof(recvbuf),0,(struct sockaddr*)&address,sizeof(address));

        printf("lenrecv = %d\tlensend = %d\n ",lenrecv,lensend);
	}
	close(servefd);
        close(clientfd);
	return 0;
}

