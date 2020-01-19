#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    int N,K,i;
	    long long sqsum=0,sum=0;
	    scanf("%d%d",&N,&K);
	    int A[N];
	    for(i=0;i<N;i++)
	    {
	        scanf("%d",&A[i]);
	        sum+=A[i];
	        sqsum+=(A[i]*A[i]);
	    }
	    if(sqsum<=sum)
	    {
	        cout<<"YES\n";
	    }
	    else
	    {
	        sort(A,A+N);
	        for(i=N-1;i>=0&&i>((N-1)-K);i--)
	        {
	            A[i]=1;
	        }
	        sum=0,sqsum=0;
	        for(i=0;i<N;i++)
	        {
	            sum+=A[i];
	            sqsum+=(A[i]*A[i]);
	        }
	        if(sqsum<=sum)
	        {
	            cout<<"YES\n";
	        }
	        else
	        {
	            cout<<"NO\n";
	        }
	    }
	}
	return 0;
}
