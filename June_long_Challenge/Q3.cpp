#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() 
{
	int T;
	long long N,K,ans;
	scanf("%d",&T);
	while(T--)
	{
	    cin>>N>>K;
	    if(N>=K)
	    {
	        ans=K-1;
	        ans=ans%mod;
	    }
	    else
	    {
	        long long  num=((K-N)/(N-1));
	        long long left=((N-K)-(num*(N-1)));
	        if(num%2==0)
	        {
	            ans=((2*(K-N)-(num-1)*(N-1))*((num/2)))%mod;
	        }
	        else
	        {
	            ans=(((2*(K-N)-(num-1)*(N-1))/2)*num)%mod;
	        }
	        ans=(ans+left)%mod;
	        ans=(ans+K-1)%mod;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

