#include <bits/stdc++.h>

#define pb push_back
#define pob pop_back
#define mp make_pair
#define F first
#define S second
#define pci pair<int,int>

using namespace std;

int L;
vector< pci > Ha;
vector< int > St;

void print(int len)
{
    int i;
    if(len==L)
    {
        char ch;
        for(i=0;i<St.size();i++)
        {
            ch=(char)St[i];
            cout<<ch;
        }
        cout<<" ";
        return;
    }
    for(i=0;i<Ha.size();i++)
    {
        if(Ha[i].S)
        {
            St.pb(Ha[i].F);
            Ha[i].S--;
            print(len+1);
            Ha[i].S++;
            St.pob();
        }
    }
}

int main()
{
	int T,i;
	string str;
	printf("Enter TC : ");
	cin>>T;
	while(T--)
	{
	    printf("Enter string : ");
	    cin>>str;
	    L=str.length();
	    int Hash[26];
	    for(i=0;i<26;i++)
	    {
	        Hash[i]=0;
	    }
	    for(i=0;i<L;i++)
	    {
	        Hash[str[i]-65]++;
	    }
        Ha.clear();
	    for(i=0;i<26;i++)
	    {
	        if(Hash[i])
	        {
	            Ha.pb(mp(i+65,Hash[i]));
	        }
	    }
	    print(0);
	    cout<<endl;
	}
	return 0;
}
