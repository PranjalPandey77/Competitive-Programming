#include <bits/stdc++.h>

using namespace std;

int tree[500000];
bool lazy[500000];

void updateRange(int node,int start,int ende,int l,int r)
{
    if(lazy[node])
    {
    	tree[node]=((ende-start+1)-tree[node]);
        if(start!=ende)
        {
        	lazy[2*node]=!lazy[2*node];
        	lazy[(2*node)+1]=!lazy[(2*node)+1];
        }
        lazy[node]=false;
    }
    if(start>ende||start>r||ende<l)
    {
    	return;
    }
    if(start>=l&&ende<=r)
    {
        tree[node]=((ende-start+1)-tree[node]);
        if(start!=ende)
        {
        	lazy[2*node]=!lazy[2*node];
        	lazy[(2*node)+1]=!lazy[(2*node)+1];
        }
        return;
    }
    int mid=(start+ende)/2;
    updateRange(node*2,start,mid,l,r);
    updateRange(node*2+1,mid+1,ende,l,r);
    if(start<ende)
    {
    	tree[node]=tree[2*node]+lazy[(2*node)+1];
    }
}

int queryRange(int node,int start,int ende,int l,int r)
{
    if(start>ende||start>r||ende<l)
    {
    	return 0;
    }
    if(lazy[node])
    {
        tree[node]=((ende-start+1)-tree[node]);
        if(start!=ende)
        {
        	lazy[2*node]=!lazy[2*node];
        	lazy[(2*node)+1]=!lazy[(2*node)+1];
        }
        lazy[node]=false;
    }
    if(start>=l &&ende<=r)
    {
    	return tree[node];
    }
    int mid=(start+ende)/2;
    int p1=queryRange(node*2,start,mid,l,r);
    int p2=queryRange(node*2+1,mid+1,ende,l,r);
    return (p1+p2);
}

int main() {
	int N,M,i,x,s,r;
	scanf("%d %d",&N,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&x,&s,&r);
		if(x==0)
		{
			updateRange(1,1,N,s,r);
		}
		else
		{
			printf("%d\n",queryRange(1,1,N,s,r));
		}
	}
	return 0;
}
