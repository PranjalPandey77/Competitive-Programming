#include<bits/stdc++.h>
#define pb push_back
#define SizeV 2010
using namespace std;
vector<int> G[SizeV];
int main()
{
    int N,M,K,i,u,v;
    cin>>N>>M>>K;
    int Deg[SizeV],marked[SizeV];
    vector<int> B,A;
    memset(Deg,0,sizeof(Deg));
    memset(marked,0,sizeof(marked));
    for(i=1;i<=M;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
        Deg[u]++;
        Deg[v]++;
    }
    for(i=1;i<=N;i++)
    {
        if(Deg[i]>=K&&marked[i]==0&&A.size()<2)
        {
            marked[i]=1;
            A.pb(i);
        }
        if(Deg[i]>=2&&marked[i]==0&&B.size()<K)
        {
            marked[i]=1;
            B.pb(i);
        }
    }
    if(A.size()==2&&B.size()==K)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
