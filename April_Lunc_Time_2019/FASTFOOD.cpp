#include <bits/stdc++.h>
#define SizeV 100009
using namespace std;
int A[SizeV],B[SizeV],pA[SizeV],sB[SizeV];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,N,i;
	long long ans;
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    for(i=1;i<=N;i++)
	    {
	        cin>>A[i];
	    }

	    for(i=1;i<=N;i++)
	    {
	        cin>>B[i];
	    }
	    memset(pA,0,sizeof(pA));
	    memset(sB,0,sizeof(sB));
	    ans=0;
	    for(i=1;i<=N;i++)
	    {
	        pA[i]=A[i]+pA[i-1];
	    }
	    for(i=N;i>=1;i--)
	    {
	        sB[i]=B[i]+sB[i+1];
	    }
	    ans=sB[1];
	    for(i=1;i<=N;i++)
	    {
	        if(pA[i]+sB[i+1]>ans)
	        {
	            ans=pA[i]+sB[i+1];
	        }
	    }
	    printf("%lld\n",ans);
	}
	return 0;
}
