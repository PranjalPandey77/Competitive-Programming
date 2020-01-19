#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    int N,i,j,k;
	    scanf("%d",&N);
	    int A[N],B[N];
	    
	    for(i=0;i<N;i++)
	    {
	        scanf("%d",&A[i]);
	        B[i]=A[i];
	    }
	    j=N-1;
	    i=0;
	    int cnt=0;
	    sort(A,A+N);
	    for(k=0;k<N;k++)
	    {
	        if(cnt%2==0)
	        {
	            B[k]=A[i++]; 
	            cnt++;
	        }
	        else
	        {
	            B[k]=A[j--];
	            cnt=0;
	        }
	    }
	    for(i=0;i<N;i++)
	    {
	        cout<<B[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

