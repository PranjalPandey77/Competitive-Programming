/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,K,r,q,Ar[100000];

void form(int ind)
{
    ll st,i;
    for(i=1;i<=ind;i++)
    {
        for(st=0;st<N;st++)
        {
            Ar[st%N]=Ar[st%N]^Ar[(N-(st%N)-1)];
        }
    }
    for(st=0;st<=r;st++)
    {
        Ar[st%N]=Ar[st%N]^Ar[(N-(st%N)-1)];
    }
}

int main() {
	ll T,i;
	cin>>T;
	while(T--)
	{
	    cin>>N>>K;
	    for(i=0;i<N;i++)
	    {
	        cin>>Ar[i];
	    }
	    q=K/N,r=K%N;
	    form(q%6);
	    for(i=0;i<N;i++)
	    {
	        cout<<Ar[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
*/
/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,K,r,Ar[100000];

void form()
{
    ll st;
    for(st=0;st<r;st++)
    {
        Ar[st%N]^=Ar[(N-(st%N)-1)];
    }
}

int main() {
	ll T,i;
	cin>>T;
	while(T--)
	{
	    cin>>N>>K;
	    for(i=0;i<N;i++)
	    {
	        cin>>Ar[i];
	    }
	    r=K%(3*N);
	    form();
	    for(i=0;i<N;i++)
	    {
	        cout<<Ar[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,K,r,Ar[100000];

int main() {
	ll T,i;
	cin>>T;
	while(T--)
	{
	    cin>>N>>K;
	    for(i=0;i<N;i++)
	    {
	        cin>>Ar[i];
	    }
	    for(i=0;i<K;i++)
        {
            Ar[i%N]^=Ar[(N-(i%N)-1)];
        }
	    for(i=0;i<N;i++)
	    {
	        cout<<Ar[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
