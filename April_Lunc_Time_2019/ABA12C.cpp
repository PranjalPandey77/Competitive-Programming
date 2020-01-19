#include<bits/stdc++.h>
#define SizeV 1000
using namespace std;
int Price[SizeV],N,K,Mrk[SizeV],ans=-1;

void solve(int cur,int ind)
{
    int i;
    if(ind>N)
    {
        return;
    }
    if(Price[ind]!=-1)
    {
        if(cur+ind==K)
        {
            Mrk[ind]=1;
            if(ans==-1)
            {
                ans=0;
                for(i=1;i<=N;i++)
                {
                    if(Mrk[i])
                    {
                        ans+=(Price[i]);
                    }
                }
            }
            else
            {
                int temp=0;
                for(i=1;i<=N;i++)
                {
                    if(Mrk[i])
                    {
                        temp+=(Price[i]);
                    }
                }
                if(temp<ans)
                {
                    ans=temp;
                }
            }
            Mrk[ind]=0;
            solve(cur,ind+1);
        }
        if(cur+ind>K)
        {
            solve(cur,ind+1);
        }
        if(cur+ind<K)
        {
            Mrk[ind]=1;
            solve(cur+ind,ind+1);
            solve(cur+ind,ind);
            Mrk[ind]=0;
            solve(cur,ind+1);
        }
    }
    else
    {
        solve(cur,ind+1);
    }
}

int main()
{
    printf("Enter T :");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C,i;
    cin>>C;
    while(C--)
    {
        cin>>N>>K;
        Price[0]=-2;
        for(i=1;i<=N;i++)
        {
            cin>>Price[i];
        }
        memset(Mrk,0,sizeof(Mrk));
        ans=-1;
        solve(0,1);
        cout<<ans<<endl;
    }
    return 0;
}
