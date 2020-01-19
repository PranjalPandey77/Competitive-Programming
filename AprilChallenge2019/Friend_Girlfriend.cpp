#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
//	printf("Entefkfhdsggkbfr T : ");
	scanf("%d",&T);
	while(T--)
	{
		int N,i,p1,W;
		long long A,te;
		scanf("%d",&N);
		char DFA[N+20],X;
		scanf("%s%*c%c",DFA,&X);
		te=0;
		A=((long long)N*(N+1))/2;
		p1=0;
		for(i=0;i<N;i++)
		{
			if(DFA[i]==X)
			{
				W=i-p1;
				te+=((long long)W*(W+1))/2;
				p1=i+1;
			}
		}
		if(p1<N)
		{
			W=N-p1;
			te+=((long long)W*(W+1))/2;
		}
		A=A-te;
		cout<<A<<endl;
	}
	return 0;
}
