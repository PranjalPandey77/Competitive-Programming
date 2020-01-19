#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

int N;
vector <int> A;

void operate()
{
    int i=0,j=2,ind;
    vector < pii > V;
    while(j<A.size())
    {
        V.clear();
        V.pb(mp(A[i],i));
        V.pb(mp(A[i+1],i+1));
        V.pb(mp(A[j],j));
        sort(V.begin(),V.end());
        ind=V[1].S;
        A.erase(A.begin()+ind);
    }
}

int main() {
	int T,i,x;
	//cout<<"ENtr T : ";
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    A.clear();
	    for(i=0;i<N;i++)
        {
            cin>>x;
            A.pb(x);
        }
        operate();
        cout<<A[0]<<" "<<A[1]<<endl;
	}
	return 0;
}
