#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    long long L,R,G,l,r;
    printf("Enter Tree : ");
    cin>>T;
    while(T--)
    {
        cin>>L>>R>>G;
        if(G<=R)
        {
            if(L%G!=0)
            {
                l=L+(((L/G)+1)*G-L);
            }
            else
            {
                l=L;
            }
            cout<<"l:"<<l<<" ";
            r=R-(R%G);
            cout<<"r:"<<r<<endl;
            if(l<r)
            {
                cout<<(((r-l)/G)+1)<<endl;
            }
            else
            if(l==r&&l%G==0)
            {
                cout<<(((r-l)/G)+1)<<endl;
            }
            else
            {
                cout<<"0\n";
            }
        }
        else
        {
            cout<<"0\n";
        }
    }
    return 0;
}
