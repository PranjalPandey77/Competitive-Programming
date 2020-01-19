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
#define MAX1 100009   // 1e5+9
#define MAX2 1000009  // 1e6+9
#define Max3 10000009 // 1e7+9
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

ll A[MAX1],MIS_ST[4*MAX1],MDS_ST[4*MAX1],N;

ll llPow(ll base,ll exponent)
{
    if(exponent==0)
    {
        return 1;
    }
    if(exponent%2==0)
    {
        return llPow((base*base)%Mod1,exponent/2);
    }
    else
    {
        return ((llPow((base*base)%Mod1,(exponent-1)/2)*base)%Mod1);
    }
}

void buildI(ll node, ll L, ll R)
{
    if(R-L==1)
    {
        if(L==1&&R==N)
        {

        }
        else
        if(L==1&&R==N)
        {

        }
    }
}

int main()
{
    ll Q,i;
    cin>>N>>Q;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
    }
    buildI(1,1,N);
    while(T--)
    {
        cout<<"Hello"<<endl;
    }
    return 0;
}
