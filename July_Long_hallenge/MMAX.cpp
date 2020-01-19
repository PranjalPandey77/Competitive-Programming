#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,i,N,k,ans;
    string K;
    printf("Enter T : ");
    cin>>T;
    while(T--)
    {
        cin>>N;
        cin>>K;
        k=0;
        for(i=0;i<K.length();i++)
        {
            k=(k*10+(K[i]-48))%N;
        }
        if(k==(N/2))
        {
            ans=N-1;
        }
        else
        if(k<(N/2))
        {
            ans=2*k;
        }
        else
        {
            ans=2*(N-k);
        }
        cout<<ans<<endl;
    }

    return 0;
}
