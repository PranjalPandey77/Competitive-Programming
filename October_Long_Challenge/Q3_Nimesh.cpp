#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll T,l,r,K,N;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        ll A[N+10],B[N+10];
        for(l=0;l<N;l++)
        {
            cin>>A[l];
        }

        for(l=0;l<N;l++)
        {
            if(l<N/2)
            {
                if(l<=K)
                {
                    r=(K/N+(K%N>l)-1)%3;
                    if(r==0)
                    {
                        B[l]=A[l]^A[N-(l%N)-1];
                    }
                    else
                    if(r==1)
                    {
                        B[l]=A[N-(l%N)-1];
                    }
                    else
                    {
                        B[l]=A[l];
                    }
                }
                else
                {
                    B[l]=A[l];
                }
            }
            else
            if((N%2==0&&l>=N/2)||(N%2==1&&l>N/2))
            {
                if(l<=K)
                {
                    r=(K/N+(K%N>l)-1)%3;
                    if(r==1)
                    {
                        B[l]=A[l]^A[N-(l%N)-1];
                    }
                    else
                    if(r==0)
                    {
                        B[l]=A[N-(l%N)-1];
                    }
                    else
                    {
                        B[l]=A[l];
                    }
                }
                else
                {
                    B[l]=A[l];
                }
            }
            else
            if(N%2==1&&l==N/2)
            {
                if(K>N/2)
                {
                    B[N/2]=0;
                }
                else
                {
                    B[N/2]=A[N/2];
                }
            }
        }

        for(l=0;l<N;l++)
        {
            cout<<B[l]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
