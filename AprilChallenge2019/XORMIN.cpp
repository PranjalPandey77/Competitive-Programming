#include<bits/stdc++.h>
#define pb push_back
#define SizeV 200009
using namespace std;
long long state[SizeV];
void BFS(long long *V,vector<long long > AD[],long long *v,long long B,long long w[])
{
    printf("Inside BFS.\n");
    queue<long long> Q;
    Q.push((*v));
    printf("%d pushed in the Queue.\n",*v);
    state[(*v)]=1;
    long long cur,i;
    long long val;
    while(!Q.empty())
    {
        cur=(int)Q.front();
        printf("%d popped and made cur.\n",cur);
        Q.pop();
        for(i=0;i<AD[cur].size();i++)
        {
            if(state[AD[cur][i]]==0)
            {
                Q.push(AD[cur][i]);
                state[AD[cur][i]]=1;
                val=w[AD[cur][i]]^B ;
                if(val>(*V))
                {
                    (*V)=val;
                    (*v)=AD[cur][i];
                    printf("Got greater node %lld *V : %lld  *v : %lld.\n",AD[cur][i],(*V),(*v));
                }
            }
        }
    }
}
int main()
{
    long long int T,N,Q,i;
    printf("Enter TSC PAC:");
    cin>>T;
    while(T--)
    {
        long long int a,b,j;
        printf("Enter N Q :");
        cin>>N>>Q;
        long long int W[N+10];
        vector<long long int> ADJ[N+10];
        printf("Enter values of nodes : ");
        for(i=1;i<=N;i++)
        {
            cin>>W[i];
        }
        printf("Enter the Graph :\n");
        for(i=1;i<N;i++)
        {
            printf("Enter src and dest :");
            cin>>a>>b;
            ADJ[a].pb(b);
            //ADJ[v].pb(u);
        }
        long long ansv=0,ansV=0;
        while(Q--)
        {
            printf("initial value ansV %lld  ; ansV %lld \n",ansv,ansV);
            printf("Enter a b :");
            cin>>a>>b;
            a=a^ansv;
            b=b^ansV;
            printf("The vertex and value is : %lld  %lld\n",a,b);
            ansV=W[a]^b;
            ansv=a;
            printf("initial vertex and value is : ");cout<<ansv<<"  "<<ansV<<endl;
            memset(state,0,sizeof(state));
            BFS(&ansV,ADJ,&ansv,b,W);
            printf("Answer is :");
            cout<<ansv<<" "<<ansV<<endl;
        }
    }
    return 0;
}
