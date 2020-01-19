#include <bits/stdc++.h>

#define pb push_back
#define MAXV 600000

using namespace std;

typedef long long ll;

vector<int> Gp[MAXV];
int N,Q,Visit[MAXV];
ll bacCnt[MAXV],K;

void dfs(int v)
{
    Visit[v]=1;
    int i,fg=0;
    for(i=0;i<Gp[v].size();i++)
    {
        if(Visit[Gp[v][i]]==0)
        {
            dfs(Gp[v][i]);
            fg++;
        }
    }

    if(fg!=0)
    {
        for(i=0;i<Gp[v].size();i++)
        {
            bacCnt[Gp[v][i]]+=bacCnt[v];
        }
        bacCnt[v]=0;
    }
}

void tick()
{
    int i;
    for(i=1;i<=N;i++)
    {
        Visit[i]=0;
    }
    dfs(1);
}


int main() {
	int x,i,y;
	cout<<"Enter N Q : ";
	cin>>N>>Q;
	for(i=1;i<N;i++)
	{
	    cin>>x>>y;
	    if(y<x)
	    Gp[y].pb(x);
	    else
	    Gp[x].pb(y);
	}
	for(i=1;i<=N;i++)
	{
	    cin>>bacCnt[i];
	}
	char op;
	for(y=0;y<Q;y++)
	{
	    tick();
	    cin>>op;
	    if(op=='+')
	    {
	        cin>>x>>K;
	        bacCnt[x]+=K;
	    }
	    else
	    {
	        cin>>x;
	        cout<<bacCnt[x]<<endl;
	    }
	}
	return 0;
}
