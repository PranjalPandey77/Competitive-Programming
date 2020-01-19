/*#include<bits/stdc++.h>

#define mp make_pair
#define pis pair<int,string>
#define pb push_back
#define F first
#define S second

using namespace std;

int main()
{
    int T,N,B,i;
    string Y;
    long long ans,X;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int n=N;
        vector < pis > Srt;
        while(n--)
        {
            cin>>B>>Y;
            Srt.pb(mp(B,Y));
        }
        int minCnt=0;
        for(i=0;i<N;i++)
        {
            if(Srt[i].F==-1)
            {
                minCnt++;
            }
        }
        if(minCnt==N-1)
        {
            string temp;
            for(i=0;i<N;i++)
            {
                if(Srt[i].F!=-1)
                {
                    ans=0;
                    X=0;
                    temp=Srt[i].S;
                    for(j=temp.length()-1;j>=0;j--)
                    {
                        if(temp[j]>='0'&&temp[j]<='9')
                        {
                            X+=(temp[j]-48)*pow(Srt[i].F,ans);
                        }
                        else
                        {

                        }
                        ans++;
                    }
                }
            }
        }
        else
        if(minCnt==N)
        {

        }
        else
        {

        }
    }
    return 0;
}
*/
#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N,Q,i,p,q;
	    cin>>N>>Q;
	    vector < long long > B;
	    for(i=1;i<N;i++)
	    {
	        cin>>p;
	        B.pb(p);
	    }
	    long long o[N]={0},e[N]={0};
	    o[0]=B[0],e[1]=B[1];
	    for(i=2,p=3;i<N,p<N;i+=2,p+=2)
	    {
	        o[i]=B[i]+o[i-2];
	        e[p]=B[p]+e[p-2];
	    }
	    while(Q--)
	    {
	        cin>>p>>q;
	        if(abs(p-q)%2==0)
	        {
	            cout<<"UNKNOWN"<<endl;
	        }
	        else
	        {
	            if(abs(p-q)==1)
	            {
	                cout<<B[min(p,q)-1]<<endl;
	            }
	            else
	            {
	                int mn=min(p,q),mx=max(p,q),fg=0;
	                long long temp=0;
	                if(mn%2==0)
	                {
	                    if(mn==2)
	                    {
	                        p=e[mx-2];
	                    }
	                    else
	                    {
	                        p=e[mx-2]-e[mn-3];
	                    }
	                    if(mx-3==mn)
	                    {
	                        q=o[mn];
	                    }
	                    else
	                    {
	                        q=o[mx-3]-o[mn];
	                    }
	                    temp=p-q;
	                }
	                else
	                {
	                    if(mn==1)
	                    {
	                        p=o[mx-2];
	                    }
	                    else
	                    {
	                        p=o[mx-2]-o[mn-3];
	                    }
	                    if(mx-3==mn)
	                    {
	                        q=e[mn];
	                    }
	                    else
	                    {
	                        q=e[mx-3]-e[mn];
	                    }
	                    temp=p-q;
	                }
	                cout<<temp<<endl;
	            }
	        }
	    }
	}
	return 0;
}
