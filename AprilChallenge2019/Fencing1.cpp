#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SizeV 100009
using namespace std;
int main()
{
	int T,N,M,K,i;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,cnt=0;
		scanf("%d%d%d",&N,&M,&K);
		set<pii> S;
		set<pii>:: iterator it;
		for(i=1;i<=K;i++)
		{
			scanf("%d%d",&a,&b);
			S.insert(mp(a,b));
			if((a==1&&b==1)||(a==1&&b==M)||(a==N&&b==1)||(a==N&&b==M))
			{
				cnt+=2;
			}
			else
			if(a==1||a==N||b==1||b==M)
			{
				cnt+=1;
			}
		}
		for(it=S.begin();it!=S.end();it++)
		{
		    a=(*it).F;
		    b=(*it).S;
			if(a+1<=N&&(S.find(mp(a+1,b))==S.end()))
            {
                cnt++;
            }
            if(a-1>=1&&(S.find(mp(a-1,b))==S.end()))
            {
                cnt++;
            }
            if(b+1<=M&&(S.find(mp(a,b+1))==S.end()))
            {
                cnt++;
            }
            if(b-1>=1&&(S.find(mp(a,b-1))==S.end()))
            {
                cnt++;
            }
		}
		cout<<cnt<<endl;
	}
	return 0;
}
