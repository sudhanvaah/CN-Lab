#include<iostream>
using namespace std;
struct node
{
  int dist[10],via[10];
};
main()
{
    node a[10];
    int n,i,j,k,c,d[10][10];
    cout<<"Enter number of nodes ";
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cin>>a[i].dist[j];
            a[i].dist[i]=0;
            d[i][j]=a[i].dist[j];
            a[i].via[j]=j;
        }
    do
    {
        c=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                {
                    if(a[i].dist[j]>d[i][k]+a[k].dist[j])
                    {
                        a[i].dist[j]=a[i].dist[k]+a[k].dist[j];
                        a[i].via[j]=k;
                        c++;
                    }
                }
    }while(c!=0);
    cout<<"Enter source node ";
    cin>>i;
    cout<<"\nDestination\tCost\tNext node";
        for(j=0;j<n;j++)
        {
                if(i==j)
                    continue;
                cout<<"\n"<<j<<"\t\t"<<a[i].dist[j]<<"\t";
                if(j==a[i].via[j])
                    cout<<"-";
                else
                    cout<<a[i].via[j];
        }
    return 0;
}
