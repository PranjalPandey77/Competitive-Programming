#include <bits/stdc++.h>
#define SizeV 1000
using namespace std;
long long Seg[SizeV],A[SizeV];
void build(int n,int l,int r)
{
    if(l==r)
    {
        Seg[n]=A[l];
    }
    else
    {
        int mid=(l+r)/2;
        build(2*n,l,mid);
        build(2*n+1,mid+1,r);
        Seg[n]=(Seg[2*n]^Seg[2*n+1]);
    }
}
long long query(int n,int s,int e,int l,int r)
{
    if(e<l||s>r)
    {
        return 0;
    }
    if(l<=s&&r>=e)
    {
        return Seg[n];
    }
    int mid=(l+r)/2;
    long long s1=query(2*n,s,e,l,mid);
    long long s2=query(2*n+1,s,e,mid+1,r);
    return (s1^s2);
}
long long getAns(long long Xr)
{
    int Bit[31],i,j=0;
    long long ans=0;
    memset(Bit,0,sizeof(Bit));
    for(i=30;i>=0;i--)
    {
        if(Xr&(1<<j))
        {

        }
        else
        {
            Bit[i]=1;
        }
        j++;
    }
    j=0;
    for(i=30;i>=0;i--)
    {
        ans+=(Bit[i]*pow(2,j));
        j++;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,N,Q,L,R,i;
	long long Xr;
	printf("Enter TC :");
	cin>>T;
	while(T--)
	{
	    printf("Enter N Q :");
	    cin>>N>>Q;
	    for(i=1;i<=N;i++)
	    {
	        cin>>A[i];
	    }
	    build(1,1,N);
	    printf("Seg tree build complete.\n");
	    while(Q--)
	    {
	        cin>>L>>R;
	        Xr=query(1,L,R,1,N);
	        cout<<getAns(Xr)<<endl;
	    }
	}
	return 0;
}
