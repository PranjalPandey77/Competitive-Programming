#include<bits/stdc++.h>

//#define mod 1e9 + 7

using namespace std;

typedef long long ll;

int main()
{
        string s,p;
        int K,i,j,k,ans=0;
        cout<<"Enter details : ";
        cin>>s;
        cin>>p;
        cin>>K;
        bool Ar[26]={false};
        map < string , bool > mp;
        cout<<"s is : "<<s<<endl;
        cout<<"p is : "<<p<<endl;
        cout<<"K is : "<<K<<endl;
        for(i=0;i<26;i++)
        {
                if(p[i]=='0')
                {
                        Ar[i]=true;
                }
        }
        for(i=1;i<=s.length();i++)
        {
                k=0;
                string str="";
                cout<<"Initialised a blank string."<<endl;
                for(j=0;j<i;j++)
                {
                       if(Ar[s[j]-'a'])
                       {
                               k++;
                       }
                       str.push_back(s[j]);
                }
                cout<<"String formed is : "<<str<<endl;
                if(k<=K&&mp[str]==false)
                {
                        ans++;
                        mp[str]=true;
                        cout<<"ans and word marked"<<endl;
                }
                for(j=i;i<s.length();j++)
                {
                        str.erase(0,1);
                        cout<<"Erased previous character "<<str<<endl;
                        if(Ar[s[j-i]-'a'])
                        {
                                k--;
                                cout<<"Erased Character was a bad letter"<<endl;
                        }
                        str.push_back(s[j]);
                        cout<<"Pushed Current character "<<str<<endl;
                        if(Ar[s[j]-'a'])
                        {
                                k++;
                                cout<<"Pushed current Character is a bad letter"<<endl;
                        }
                        if(k<=K&&mp[str]==false)
                        {
                                ans++;
                                mp[str]=true;
                                cout<<"ans and word marked"<<endl;
                        }
                }
        }
        cout<<ans;
        return 0;
}
