#include<iostream>
using namespace std;
main()
{
    int i,j,m,n,u,v,dist[10][10],flag[10],cost[10];
    cout<<"Enter size of graph ";
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>dist[i][j];
    cout<<"Enter source vertex ";
    cin>>v;
    for(i=0;i<n;i++)
        flag[i]=0,cost[i]=dist[v][i];
    for(i=0;i<n;i++)
    {
        m=999;
        for(j=0;j<n;j++)
            if(m>cost[j] && !flag[j])
                m=cost[j],u=j;
        flag[u]=1;
        for(j=0;j<n;j++)
            if(cost[j]>cost[u]+dist[u][j])
                cost[j]=cost[u]+dist[u][j];
    }
    for(i=0;i<n;i++)
        if(i!=v)
            cout<<"\n"<<v<<"->"<<i<<" : "<<cost[i];
}
