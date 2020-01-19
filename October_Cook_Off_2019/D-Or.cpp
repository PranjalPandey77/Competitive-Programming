#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll L,R,ans,moi1,moi2;

int bn1[65],bn2[65];

ll getPow(ll b,ll ex)
{
    if(ex==0)
    {
        return 1;
    }
    if(ex%2==0)
    {
        return getPow(b*b,ex/2);
    }
    else
    {
        return getPow(b*b,(ex-1)/2)*b;
    }
}

ll getNum(int bits[])
{
    ll te=0;
    int i=63;
    while(i>=0)
    {
        te+=(bits[i]*getPow(2,(63-i)));
        i--;
    }
    return te;
}

void findNum()
{
    int i;
    for(i=moi1;i<=63;i++)
    {
        if(bn1[i]==0&&bn2[i]!=0)
        {
            i++;
            break;
        }
    }
    while(i<=63)
    {
        bn2[i]=1;
        i++;
    }
}

void getAns()
{
    int i;
    for(i=0;i<=64;i++)
    {
        bn1[i]=bn2[i]=0;
    }
    i=63;
    ll tn=L;
    while(tn>0)
    {
        bn1[i]=tn%2;
        tn/=2;
        i--;
    }
    moi1=i+1;
    i=63;
    tn=R;
    while(tn>0)
    {
        bn2[i]=tn%2;
        tn/=2;
        i--;
    }
    moi2=i+1;
    if(moi2<moi1)
    {
        for(i=moi2;i<=63;i++)
        {
            bn2[i]=1;
        }
    }
    else
    if(moi2==moi1)
    {
        findNum();
    }
    ans=getNum(bn2);
}

int main() {
	int T;
	//cout<<"Enter TDS : ";
	cin>>T;
	while(T--)
	{
	    cin>>L>>R;
	    getAns();
        cout<<ans<<endl;
	}
	return 0;
}
