#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,K,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		int ar[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&ar[i]);
		}
		int S[N];
		for(i=N-1;i>=0;i--)
		{
			if(i+K<N)
			{
				S[i]=ar[i]+S[i+K];
			}
			else
			{
				S[i]=ar[i];
			}
		}
		sort(S,S+N);
		cout<<S[N-1]<<endl;
	}
	return 0;
}
