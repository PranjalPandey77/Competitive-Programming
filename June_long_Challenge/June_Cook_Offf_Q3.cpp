#include <bits/stdc++.h>
#define pii pair < int , int >
#define tiii tuple < int , int , int >
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define mt make_tuple
using namespace std;

int main()
{
	int T,N,M,i,D,F,B;
	long long Profit=0;
	vector<int> seq;
	printf("Enter %d # TT :",'#');
	cin>>T;
	while(T--)
	{
	    cin>>N>>M;
	    int Num[M+100];
	    for(i=1;i<=M;i++)
	    {
	        cin>>Num[i];
	    }
	    int Hash[M+100];
	    memset(Hash,0,sizeof(Hash));
	    vector< pii > hsh;
	    vector< tiii > Store;
	    for(i=1;i<=N;i++)
	    {
	        cin>>D>>F>>B;
	        Store.pb(mt(D,F,B));
	        Hash[D]++;
	    }
	    seq.clear();
	    Profit=0;
	    for(i=1;i<=M;i++)
	    {
	        if(Hash[i]==0||Hash[i]<Num[i])
	        {
	            hsh.pb(mp(i,Num[i]-Hash[i]));
	        }
	    }
	    for(i=0;i<N;i++)
	    {
	        if(Num[get<0>(Store[i])]>0)
	        {
	            Profit+=(get<1>(Store[i]));
	            seq.pb(get<0>(Store[i]));
	            Num[get<0>(Store[i])]-=1;
	        }
	        else
	        {
	            if(hsh.size()>0)
	            {
	                Profit+=(get<2>(Store[i]));
	                seq.pb(hsh[0].f);
	                hsh[0].s=hsh[0].s-1;
	                if(hsh[0].s==0)
	                {
	                    hsh.erase(hsh.begin());
	                }
	            }
	            else
	            {
	                break;
	            }
	        }
	    }
	    cout<<Profit<<endl;
	    for(i=0;i<seq.size();i++)
	    {
	        cout<<seq[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
