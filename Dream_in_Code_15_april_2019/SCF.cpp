#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main()
{
    int u,v,N,M,i,ans=0;
   // printf("Enter N M :");
    cin>>N>>M;
    int Tp[N+1];
    vector<int> Graph[N+1];
    Tp[0]=-1;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&Tp[i]);
    }
    vector<pii> Edges;
    map< int , map < int , int > > MP;
    for(i=1;i<=M;i++)
    {
        cin>>u>>v;
        Graph[u].pb(v);
        Edges.pb(mp(u,v));
        MP[u][v]=1;
    }
    for(i=0;i<Edges.size();i++)
    {
        if(MP[Edges[i].S][Edges[i].F]==0)
        {
            ans++;
            Graph[Edges[i].S].pb(Edges[i].F);
        }
    }
    int tp0=0,tp1=0;
    for(i=1;i<=N;i++)
    {
        if(Graph[i].size()==0&&Tp[i]==0)
        {
            tp0++;
        }
        else
        if(Graph[i].size()==0&&Tp[i]==1)
        {
            tp1++;
        }
    }
    ans+=(tp0+(2*(tp1)));
    cout<<ans;
    return 0;
}
