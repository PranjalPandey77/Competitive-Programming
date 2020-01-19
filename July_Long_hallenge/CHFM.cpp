#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N,i,ans;
	printf("Enter T :");
	scanf("%d",&T);
	while(T--)
	{
	    printf("Enter N :");
	    scanf("%d",&N);
	    vector<int> A(N);
	    double Av=0,Tt=0;
	    for(i=0;i<N;i++)
	    {
	        cin>>A[i];
	        Av+=(A[i]);
	        Tt+=(A[i]);
	    }
	    Av/=N;
	    cout<<"Average is : " <<Av<<" and Total is : "<<Tt<<endl;
	    ans=-1;
	    for(i=0;i<N;i++)
	    {
	        Tt-=(A[i]);
	        if((Tt/(N-1))==Av)
	        {
	            ans=i+1;
	            break;
	        }
	        else
	        {
	            Tt+=(A[i]);
	        }
	    }
	    if(ans==-1)
	    {
	        printf("Impossible\n");
	    }
	    else
	    {
	        printf("%d\n",ans);
	    }
	}
	return 0;
}
