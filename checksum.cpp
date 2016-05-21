#include<iostream>
using namespace std;
#include<math.h>
#include<cstring>
 int sender(char b[10],int k)
 {
        int checksum,sum=0,i;
        cout<<"\n****SENDER****\n";
        for(i=0;i<k;i++)
      		sum+=(int)b[i];
        cout<<"SUM IS:"<<sum;
    	checksum=~sum;
    	cout<<"\nSENDER's CHECKSUM IS:"<<checksum;
    	return checksum;
}


int receiver(char c[10],int k,int scheck)
{
        int checksum,sum=0,i;
     	cout<<"\n\n****RECEIVER****\n";
     	for(i=0;i<k;i++)
      		sum+=(int)c[i];
      	cout<<" RECEIVER SUM IS:"<<sum;
      	sum=sum+scheck;
      	checksum=~sum;
      	cout<<"\nRECEIVER's CHECKSUM IS:"<<checksum;
      		return checksum;
}
int checksum(char *a,int check=0)
{
    int s = strlen(a);
    int sum = check;
    for(int i=0;i<s;i++)
    {
        sum+=(int)a[i];
    }
    sum=~sum;
    if(check==0)
    {
        cout<<"Checksum is "<<sum;
        return sum;
    }
    if(sum!=0)
    {
        cout<<"There was an error in transmission";
    }
    else
        cout<<"Transmission was error free";
    return sum;

}
int main()
{
     	int i,m,check,ch;
     	char a[100];
     	do
        {
            cout<<"\n\n1. Encode\n2. Decode\n3. Exit\n";
            cin>>ch;
            switch(ch)
                {
                case 1:
                    cout<<"Enter your message ";
                    cin>>a;
                    checksum(a);
                    break;
                case 2:
                    cout<<"\nEnter received message ";
                    cin>>a;
                    cout<<"\nEnter received checksum ";
                    cin>>check;
                    checksum(a,check);
                    break;
                default: break;
                }
        }while(ch!=3);
        return 0;
}
