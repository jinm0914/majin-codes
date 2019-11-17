
#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <fstream>
using namespace std;
std::ofstream outfile;
struct timeval send_time,recv_time;
char ints[10]= {0};
char intus[6]= {0};
char intcount[5]={0};

void* recvsocket(void *ptr) 
{  
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);

    socklen_t addrlen = sizeof(servaddr);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6981);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
      
    char recvbuf[1024] = {0};
	while (1)  
	{   
	    memset(recvbuf, 0, sizeof(recvbuf)); 
        memset(ints, 0, sizeof(ints));
        memset(intus, 0, sizeof(intus));
        memset(intcount, 0, sizeof(intcount));
	    int len =recvfrom(sockfd, recvbuf,sizeof(recvbuf), 0, (struct sockaddr *)&servaddr, &addrlen);
        gettimeofday(&recv_time,NULL);
        
	    if (len < 0){
            printf("***** recv ret = %d******\n",len);
            break; 
        }   
        memcpy(ints,&recvbuf[7],8);
        memcpy(intus,&recvbuf[15],6);
        
        cout <<"**RECV  TIME**"<<recvbuf[5]<<recvbuf[6]<<ints<<"***"<<atoi(intus)<<"***RECV_ID =***"<<recvbuf[0]<<recvbuf[1]<<recvbuf[2]<<recvbuf[3]<<recvbuf[4]<<endl;   
        cout <<"***NOW TIME***"<<recv_time.tv_sec<<"***"<<recv_time.tv_usec<<endl;
        cout<<"   RECV_LEN =   "<<len<<endl;
   
        long int delay = 0;
		if(recv_time.tv_usec > atoi(intus))
			delay = ((recv_time.tv_usec - atoi(intus))/1000)/2;
		else
			delay = ((1000000+recv_time.tv_usec - atoi(intus)) /1000)/2;  
        outfile<<"recvFromV2X =  "<<recvbuf[0]<<recvbuf[1]<<recvbuf[2]<<recvbuf[3]<<recvbuf[4]<<"        "<<recvbuf[22]<<"        "<<recvbuf[5]<<recvbuf[6]<<atoi(ints)<<"	    "<<atoi(intus)<<endl; 
        outfile<<"  nowTime   =                        "<<recv_time.tv_sec<<"	    "<<recv_time.tv_usec<<endl;
        outfile<<"  THIS MSG                                                          "<<delay<<endl; 
        outfile<<" "<<endl;         
	    printf("recv = %s\n", recvbuf);  
	}
    outfile.close();  
	return NULL;  
}  

int main(int argc, const char * argv[]) 
{
    outfile.open ("dataTime.txt"); 
    outfile<<"  status         ID        msg           s            us        delay/ms"<<endl;
    std::cout << "t server" << std::endl;
    const char* ip ="192.168.253.10";  //htonl(INADDR_ANY);
    int port = 6980;
    std::cout << "ip=" << ip << " port="<<port << std::endl;

    int fd;
    fd = socket(PF_INET,SOCK_DGRAM , 0);
    if(0 >=fd){
        perror(" socket(PF_INET,SOCK_DGRAM , 0)** Failed:"); 
        exit(1);
    }
    char sendout[1024];

    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);

    pthread_t thrd1;
    pthread_create(&thrd1, NULL, recvsocket, &fd); 
    int count = 0;
    
    while(1){  
        int j =0;   
	    usleep(30000); 
    
        gettimeofday(&send_time,NULL);

        j=sprintf(sendout,"%5d",count+1);
        j+=sprintf(sendout+j,"%10ld",send_time.tv_sec);
        j+=sprintf(sendout+j,"%6ld",send_time.tv_usec);
  
        for(int i = 21;i < 1023 ;i++)sendout[i] = 'w';
        sendout[1024] = '\0';	
	
        int len = sendto(fd, sendout, sizeof(sendout),0,(struct sockaddr*)&address,sizeof(address));
	    count++;
        printf("sendout:%s\n   SEND_LEN = %d\n",sendout,len);  
        outfile<<" sendToV2X  =  "<<sendout[0]<<sendout[1]<<sendout[2]<<sendout[3]<<sendout[4]<<"        "<<sendout[22]<<"        "<<send_time.tv_sec<<"	    "<<send_time.tv_usec<<endl;
        cout <<"**SEND  TIME**"<<send_time.tv_sec<<"***"<<send_time.tv_usec<<"***RECV_ID =***"<<sendout[0]<<sendout[1]<<sendout[2]<<sendout[3]<<sendout[4]<<endl;  
    }                
    close(fd);
    return 0;
}

