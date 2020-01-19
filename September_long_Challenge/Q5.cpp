#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

typedef long long ll;

int main() {
	int T;
	ll A,B,C,ans,f1,f2,t1,sqt,i,j;
	cout<<"Enter TT : ";
	cin>>T;
	while(T--)
	{
	    cout<<"Enter A B C : ";
	    cin>>A>>B>>C;
	    ans=0;
	    for(i=1;i<=B;i++)
	    {
	        t1=i*i;
	        if((A-1)*(C-1)<=t1)
            {
                break;
            }
	        sqt=sqrt(t1);
	        for(j=1;j<=sqt;j++)
	        {
	            f1=j,f2=t1/j;
	            if(f1+1<=A)
	            {
	                if(f2+2<=C&&(C-f2-1)>=0)
	                {
	                    ans=(ans+C-f2-1)%mod;
	                }
	            }
	            if((A-f1-1)>=0&&(C-f2)>=0)
	            {
	                ans=(ans+((A-f1-1)*(C-f2)%mod))%mod;
	            }
	            if(f1!=f2&&(A-f1-1)>=0)
                {
                    f1=t1/j,f2=j;
                    if(f2+1<=C)
                    {
                        if(f1+2<=A)
                        {
                            ans=(ans+A-f1-1)%mod;
                        }
                    }
                }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
