//client.c
#include<stdlib.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
void main()
{
	char fname[255],buff[1024];
	int n,cs;
	struct sockaddr_in a;
	a.sin_family=AF_INET;
	a.sin_port=htons(15000);
	inet_pton(AF_INET,argv[1],&a);
	cs=socket(AF_INET,(sockaddr *)&a,sizeof(a));
	printf("Enter filename ");
	scanf("%s",fname);
	send(cs,fname,255,0);
	while(recv(cs,buff,1024,0))
		printf("%s",buff);
}
