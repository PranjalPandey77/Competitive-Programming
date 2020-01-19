#include<bits/stdc++.h>
using namespace std;
int checkVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return 1;
    }
    return 0;
}
int checkConso(char ch)
{
    if(!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'))
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,i,N,ans;
    string str;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>N;
        cin>>str;
        for(i=0;i<N-1;i++)
        {
            if(checkConso(str[i])&&checkVowel(str[i+1]))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
