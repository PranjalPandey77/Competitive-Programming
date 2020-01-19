#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	long long C,X,ans,po,cc;
	cout<<"Enter T : ";
	cin>>T;
	while(T--)
	{
	    cin>>C>>X;
        po=X;
        if(X==1)
        {
            ans=C;
        }
        else
	    if(C<X)
	    {
	        ans=C;
	    }
	    else
	    if(C==X)
	    {
	        ans=1;
	    }
	    else
	    {
	        while(1)
	        {
	            po*=X;
	            if(po>C)
	            {
	                po/=X;
	                break;
	            }
	        }
	        cc=C/po;
	        ans=cc+(C-(po*cc));
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
