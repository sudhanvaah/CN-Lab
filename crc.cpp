#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
#define div_size 7
char d[div_size]="101101",dt[20],r[div_size]="0000",cw[20];
int l,i,j=0,k,flag=0;
void crc()
{
    j=0;
    for(i=0;i<div_size-1;i++)
    {
        r[i]=dt[i];
    }
    cout<<endl<<"dataword : "<<dt<<endl;
    while(j<(l-div_size+2))
    {
        k=j+1;
        if(r[0]=='0')
        {

            for(i=0;i<div_size-2;i++)
            {
                r[i]=r[i+1];
                k++;
            }
        }
        else
        {
            for(i=0;i<div_size-2;i++)
            {
                r[i]=((int)r[i+1]-48)^((int)d[i+1]-48)+48;
                k++;
            }
        }
        r[i]=dt[k];
        j++;
        cout<<"\nIntermediate remainder: "<<r;
    }

}
main()
{

    cout<<"Enter the data word"<<endl;
    cin>>dt;
    l=strlen(dt);
    cout<<"Divisor is : "<<d;
    for(i=0;i<16;i++)
    {
        dt[l++]='0';
    }
    dt[l]='\0';
    crc();
    cout<<"\nCodeword: ";
    for(i=0;i<(l-div_size+2);i++)
        cout<<dt[i];
    for(i=0;i<div_size-2;i++)
        cout<<r[i];
    cout<<"\nEnter received codeword ";
    cin>>dt;
    crc();
    for(i=0;i<strlen(r);i++)
    {
        if(r[i]!='0')
        {
            cout<<"\nError in transmission";
            flag=1;
            break;
        }
    }
    if(!flag)
        cout<<"\nError free transmission";

}
