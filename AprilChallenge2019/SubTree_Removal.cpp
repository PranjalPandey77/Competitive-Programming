#include <bits/stdc++.h>
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


const int SizeV = 1e5 + 9;
long long A[SizeV],/*Dp[SizeV],*/N,X,state[SizeV];
vector<int> ADJ[SizeV];
long long Max(long long a,long long b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

long long dfs(int V)
{
    int i;
    state[V]=1;
    if(ADJ[V].size()==0)
    {
        //Dp[V]=Max(A[V],-X);
        state[V]=2;
        //return Dp[V];
        return Max(A[V],-X);
    }
    long long temp=0;
    for(i=0;i<ADJ[V].size();i++)
    {
        if(state[ADJ[V][i]]==0)
        {
            temp+=dfs(ADJ[V][i]);
        }
    }
    state[V]=2;
    //Dp[V]=Max(temp+A[V],-X);
    return Max(temp+A[V],-X);;
}

long long DFS(int S)
{
    int i;
    //Dp[S]=0;
    long long ans=0;
    for(i=0;i<ADJ[S].size();i++)
    {
        if(state[ADJ[S][i]]==0)
        {
            ans+=dfs(ADJ[S][i]);
        }
    }
    return max(ans+A[S],-X);
}
int main()
{
    IOS;
    int T,i;
    printf("Enter TCShghcgv:");
    scanf("%d",&T);
    while(T--)
    {
        int u,v;
        printf("Enter N X :");
        scanf("%d%d",&N,&X);
        for(i=0;i<N;i++)
        {
            printf("Enter A[%d] : ",i);
            scanf("%d",&A[i]);
            state[i+1]=0;
            //Dp[i+1]=0;
        }
        printf("Now enter the graph :\n");
        for(i=1;i<N;i++)
        {
            printf("Enter u v :");
            scanf("%d%d",&u,&v);
            ADJ[u].pb(v);
        }
        printf("Answer is : ");
        cout<<DFS(1)<<endl;
        for(i=0;i<SizeV;i++)
        {
            ADJ[i].clear();
        }
    }
    return 0;
}
