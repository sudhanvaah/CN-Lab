//client.c
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char **argv)
{
  int cs,n;
  char buffer[1024],fname[255];
  struct sockaddr_in a;
  a.sin_family=AF_INET;
  a.sin_port=htons(15000);
  inet_pton(AF_INET,argv[1],&a.sin_addr);
  cs=socket(AF_INET,SOCK_STREAM,0);
  connect(cs,(struct sockaddr*)&a,sizeof(a));
  printf("Enter filename ");
  scanf("%s",fname);
  send(cs,fname,255,0);
  while(n=recv(cs,buffer,1024,0))
  	printf("%s",buffer);
  
}
