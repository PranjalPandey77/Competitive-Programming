#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;

ll N,zc,nwz;

bool getAns()
{
    int pc=0;
    while(nwz>1)
    {
        if(nwz%2!=0)
        {
            return false;
        }
        nwz/=2;
        pc++;
    }
    //cout<<"pc is "<<pc<<endl;
    if(nwz==1&&pc<=zc)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool get2P()
{
    vector <ll> dig;
    ll t=N;
    int i;
    while(t)
    {
        dig.insert(dig.begin(),(t%10));
        t/=10;
    }
    t=0;
    i=dig.size()-1;
    while(i>=0)
    {
        if(dig[i]>0)
        {
            break;
        }
        zc++;
        i--;
    }
    int l=i;
    i=0;
    while(i<=l)
    {
        t=(t*10)+dig[i];
        i++;
    }
    nwz=t;
    //cout<<"t is : "<<t<<" and zc is : "<<zc<<endl;
    if(getAns())
    {
        return true;
    }
    return false;
}

int main() {
	int T;
	//cout<<"Enter Tddvbb : ";
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    zc=0;
	    if(get2P())
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    {
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
