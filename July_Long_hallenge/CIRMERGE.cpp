#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int T,i,j,N,t,a,b,Mn;
	ll ans;
	printf("Enter TT :");
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        vector<ll> A(N);
        for(i=0;i<N;i++)
        {
            cin>>A[i];
        }
        ans=0;
        for(i=0;i<N-1;i++)
        {
            if(A.size()==1)
            {
                ans+=(A[0]);
                break;
            }
            else
            {
               Mn=A[0]+A[1];
               a=0,b=1;
            }
            t=A.size();
            for(j=1;j<t;j++)
            {
                if(A[j]+A[(j+1)%t]<Mn)
                {
                    a=j,b=(j+1)%t,Mn=A[j]+A[(j+1)%t];
                }
            }
            if(a==t-1)
            {
                A[0]=Mn;
                ans+=Mn;
                A.erase(A.end()-1);
            }
            else
            {
                A[a]=Mn;
                ans+=Mn;
                A.erase(A.begin()+a+1);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
