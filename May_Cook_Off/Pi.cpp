#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
   // cout<<"Enter TCS :";
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T,N,i,D,d;
    vector<int> Q;
	cin>>T;
	while(T--)
	{
	    Q.clear();
	    cin>>N;
	    d=0;
	    D=22;
	    for(i=1;i<=N;i++)
	    {
	       // q=D/7;
	        //r=D%7;
	        Q.pb(D/7);
	        D=D%7;
	        //cout<<q<<" ";
	        if(D<7&&d==0)
	        {
	            Q.pb(-1);
	            D=D*10;
	            d=1;
	        }
	        else
	        if(D<7&&d==1)
	        {
	            D=D*10;
	        }
	        /*else
	        {
	            D=r;
	        }*/
	    }
	   // cout<<"Ans : ";
	    if(N==1)
	    {
	        cout<<Q[0]<<endl;
	    }
	    else
	    {
	        cout<<Q[N]<<endl;
	    }
	}
	return 0;
}
