#include <bits/stdc++.h>

#define pb push_back
#define MAXV 200001

using namespace std;

int N,M,SG[MAXV],Edges[MAXV];
vector<int> Gp[MAXV];

int main()
{
	int T,i,u,v;
	cin>>T;
	while(T--)
	{
	    cin>>N>>M;
	    for(i=1;i<=N;i++)
	    {
	        SG[i]=1;
	        Edges[i]=0;
	        Gp[i].clear();
	    }
	    for(i=1;i<=M;i++)
	    {
	        cin>>u>>v;
	        Gp[u].pb(v);
	        Gp[v].pb(u);
	        Edges[u]++;
	        Edges[v]++;
	    }
	    if(M%2!=0)
	    {
            u=0;
            for(i=1;i<=N;i++)
            {
                if(Edges[i]%2!=0)
                {
                    SG[i]++;
                    u+=2;
                    break;
                }
            }
            if(u==0)
            {
                for(i=1;i<=N;i++)
                {
                    if(Gp[i].size()>0)
                    {
                        SG[i]=2;
                        SG[Gp[i][0]]=3;
                        u=3;
                        break;
                    }
                }
            }
	    }
	    cout<<u<<endl;
	    for(i=1;i<=N;i++)
	    {
	        cout<<SG[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
