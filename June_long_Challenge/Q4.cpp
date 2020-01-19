#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int GCD(int A,int B)
{
    if(A%B==0)
    {
        return B;
    }
    return GCD(B,A%B);
}

int main() 
{
	int T,i,N;
	printf("Enter T : ");
	cin>>T;
	while(T--)
	{
		printf("Enter N : ");
	    cin>>N;
	    int Ar[N+100];
	    for(i=0;i<N;i++)
	    {
	        cin>>Ar[i];
	    }
	    vector<int> A,B;
	    map<int,int> Mp;
	    int ga=Ar[0],gb=0,temp;
	    A.pb(Ar[0]);
	    Mp[Ar[0]]++;
	    printf("A[0]=%d pushed in Vector A.\n",A[0]);
	    for(i=1;i<N;i++)
	    {
	    	printf("Start %d.\n",i);
	    	printf("A[%d]=%d .\n",i,A[i]);
	        if(Mp[A[i]]==0)
	        {
	        	printf("Mp[A[%d]]==0.\n",i);
	            Mp[A[i]]++;
	        	temp=GCD(ga,Ar[i]);
	        	printf("temp=%d\n",temp);
	        	if(temp>ga)
	        	{
	            	A.pb(Ar[i]);
	            	printf("ga=%d temp>ga.\n",ga);
	            	ga=temp;
	        	}
	        	else
	        	{
	            	if(gb==0)
	            	{
	                	gb=A[i];
	            	}
	            	else
	            	{
	                	gb=GCD(gb,A[i]);
	            	}
	            	B.pb(A[i]);
	        	}
	        }
	        else
	        {
	            B.pb(A[i]);
	            if(gb==0)
	            {
	                gb=A[i];
	            }
	            else
	            {
	                temp=GCD(gb,A[i]);
	                if(temp>gb)
	                {
	                    gb=temp;
	                }
	            }
	        }
	    }
	    printf("Answer : ");
	    cout<<(ga+gb)<<endl;
	}
	return 0;
}

