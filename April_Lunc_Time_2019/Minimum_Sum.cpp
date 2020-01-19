#include <bits/stdc++.h>
using namespace std;
long long getNum(int Bit[])
{
    int i,j=0;
    long long res=0;
    for(i=31;i>=0;i--)
    {
        res+=(Bit[i]*pow(2,j));
        j++;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,i,N,cnt,j;
	long long ans,X;
	int Bit[32];
	//printf("Enter T :");
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    int A[N];
	    for(i=0;i<N;i++)
	    {
	        cin>>A[i];
	    }
	    memset(Bit,0,sizeof(Bit));
        for(i=0;i<32;i++)
        {
            cnt=0;
            for(j=0;j<N;j++)
            {
                if(A[j]&(1<<i))
                {
                    cnt++;
                }
            }
            if(cnt>=((N/2)+1))
            {
                Bit[31-i]=1;
            }
        }
        X=getNum(Bit);
        ans=0;
        for(i=0;i<N;i++)
        {
            ans+=(X^A[i]);
        }
        printf("%lld\n",ans);
	}
	return 0;
}
