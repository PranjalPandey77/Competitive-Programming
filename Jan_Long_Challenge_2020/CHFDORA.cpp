/*
Author : Pranjal Pandey
IT 3rd Year
MNNIT Allahabad
*/

#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define Mod1 1000000009
#define Mod2 1000000007
#define INF 999999999999999999
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pof_front
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define pll pair<ll,ll>
#define tlll tuple<ll,ll,ll>
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main()
{
    ll T,N,M,i,j,k,l,ans;
    cout<<"Enter Token : ";
    cin>>T;
    while(T--)
    {
        cout<<"Enter N M : ";
        cin>>N>>M;
        ll mat[N+10][M+10];
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                cin>>mat[i][j];
            }
        }
        ans=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                cout<<"The center is : "<<i<<" : "<<j<<endl;
                k=1;
                l=0;
                cout<<"Ans val is S: "<<ans<<endl;
                while(((i-k)>=0)&&((i+k)<N)&&((j-k)>=0)&&((j+k)<M))
                {
                    if((mat[i-k][j]==mat[i+k][j])&&(mat[i][j-k]==mat[i][j+k]))
                    {
                        l++;
                    }
                    else
                    {
                        break;
                    }
                    k++;
                }
                ans=ans+l+1;
                cout<<"Ans val is E: "<<ans<<endl;
            }
        }
        cout<<"Answer is : "<<ans<<endl;
    }
    return 0;
}
