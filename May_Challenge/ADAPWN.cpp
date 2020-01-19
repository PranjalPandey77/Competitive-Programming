#include <bits/stdc++.h>
//#define SizeV 109
//#define mod 1000000007
using namespace std;

int main()
{
	int T,i,fg;//N;
	long long N,M;
	printf("Enter TTzxjvhvdsvvbSS :");
	scanf("%d",&T);
    /*long long  FC[SizeV],SC[SizeV],ans[SizeV];
    FC[0]=-1,SC[0]=-1;
    FC[1]=1,SC[1]=0;
    ans[0]=-1,ans[1]=1;
    for(i=2;i<SizeV;i++)
    {
        FC[i]=(FC[i-1]*i)%mod;
        SC[i]=(((SC[i-1]+1)*i)-1)%mod;
        ans[i]=(FC[i]*i+SC[i])%mod;
    }*/
	while(T--)
	{
	    fg=1;
	    scanf("%lld%lld",&N,&M);
        if(N==1||M==1||N==M)
        {
            printf("Ari\n");
        }
        else
        {
            int T=-1;
            while(N>0&&M>0)
            {
                if(T==-1)
                {
                    T=1;
                }
                else
                if(T==1)
                {
                    if(N==1||M==1||N==M)
                    {
                        printf("Ari\n");
                        fg=0;
                        break;
                    }
                    T=0;
                }
                else
                if(T==0)
                {
                    if(N==1||M==1||N==M)
                    {
                        printf("Rich\n");
                        fg=0;
                        break;
                    }
                    T=1;
                }
                if(N>M)
                {
                    if(N/M==1)
                    {
                        N=N-((M)*(N/M));
                    }
                    else
                    {
                        N=N-((M-1)*(N/M));
                    }
                }
                else
                if(N<M)
                {
                    if(M/N==1)
                    {
                        M=M-((N)*(M/N));
                    }
                    else
                    {
                        M=M-((N-1)*(M/N));
                    }
                }
            }
            if(T==1&&fg)
            {
                printf("Ari\n");
            }
            else
            if(T==0&&fg)
            {
                printf("Rich\n");
            }
        }
	}
	return 0;
}
