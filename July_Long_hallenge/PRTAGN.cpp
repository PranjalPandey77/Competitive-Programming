#include <bits/stdc++.h>

using namespace std;

bool check(int num)
{
    int cnt=0;
    while(num)
    {
        num=num&(num-1);
        cnt++;
    }
    if(cnt%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
	int T,i,Q,X,xr;
	printf("Enter TRee : ");
	scanf("%d",&T);
	set < int > :: iterator it;
	while(T--)
	{
	    int E=0,O=0;
	    printf("Enter Q : ");
	    scanf("%d",&Q);
	    set < int > S;
	    while(Q--)
	    {
	        printf("Enter X : ");
	        scanf("%d",&X);
	        if(S.find(X)==S.end())
	        {
	            S.insert(X);
	            printf("X not in Set ,inserted.\n");
	            if(check(X))
	            {
	                printf("X has even parity.\n");
	                E++;
	            }
	            else
	            {
	                printf("X has odd parity.\n");
	                O++;
	            }
	            printf("Going to for loop.\n");
	            //if(S.size()>1)
	            //{
	                for(it=S.begin();it!=S.end();it++)
                    {
                        xr=X^(*it);
                        cout<<"Xor of X = "<<X<<" and (*it) = ";
                        cout<<(*it)<<" is : "<<xr<<endl;
                        if(S.find(xr)==S.end()&&xr!=0)
                        {
                            S.insert(xr);
                            printf("xr= %d not in S , inserted.\n",xr);
                            if(check(xr))
                            {
                                printf("xr has even parity.\n");
                                E++;
                            }
                            else
                            {
                                printf("xr has odd parity.\n");
                                O++;
                            }
                        }
                    }
	            //}
	        }
	        cout<<"Answer is : "<<E<<" "<<O<<endl;
	    }
	}
	return 0;
}
