#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int Ar[100010],Dp[100010],N,P[1000100];
vector < int > ind[1000100];

void getAns()
{
    int i,j,t,T,k;
    for(i=0;i<N;i++)
    {
        T=sqrt(Ar[i]);
        for(j=1;j<=T;j++)
        {
            if(Ar[i]%j==0&&P[j])
            {
                for(k=0;k<ind[j].size();k++)
                {
                    if(ind[j][k]>i)
                    {
                        Dp[ind[j][k]]++;
                    }
                }
                t=Ar[i]/j;
                if(j!=t&&P[t])
                {
                    for(k=0;k<ind[t].size();k++)
                    {
                        if(ind[t][k]>i)
                        {
                            Dp[ind[t][k]]++;
                        }
                    }
                }
            }
        }
    }
}

int main() {
	int T,i,ans;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d",&N);
	    for(i=0;i<N;i++)
	    {
	        scanf("%d",&Ar[i]);
	        P[Ar[i]]=1;
	        Dp[i]=0;
	        ind[Ar[i]].pb(i);
	    }
	    ans=INT_MIN;
	    getAns();
	    for(i=0;i<N;i++)
	    {
	        ans=max(ans,Dp[i]);
	        P[Ar[i]]=0;
	        ind[Ar[i]].clear();
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
