//server.c
#include<stdlib.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main()
{
	int cs,ns,fd,n;
	char buff[1024],fname[255];
	struct sockaddr_in a;
	a.sin_family=AF_INET;
	a.sin_port=htons(15000);
	a.sin_addr.s_addr=INADDR_ANY;
	cs=socket(AF_INET,SOCK_STREAM,0);
	bind(cs,(struct sockaddr *)&a,sizeof(a));
	listen(cs,3);
	ns=accept(cs,(struct sockaddr *)NULL,NULL);
	recv(ns,fname,255,0);
	fd=open(fname,O_RDONLY);
	n=read(fd,buff,1024);
	send(ns,buff,n,0);
	return close(cs);
}
