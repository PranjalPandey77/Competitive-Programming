#include <bits/stdc++.h>

#define pb push_back
#define SIZE 100000

using namespace std;

typedef long long ll;

bool isPrime(ll n)
{
    if(n<=1)
    {
        return false;
    }
    if(n<=3)
    {
        return true;
    }
    if(n%2==0||n%3==0)
    {
        return false;
    }
    ll i;
    for(i=5;i*i<=n;i=i+6)
    {
        if(n%i==0||n%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
	int T,i,j;
	//printf("Enter T :");
	scanf("%d",&T);
	ll x,Qa;
	string BQa;
	vector < ll > PrimeNum;
	for(i=0;i<SIZE;i++)
	{
	    PrimeNum.pb(1);
	}
	PrimeNum[0]=PrimeNum[1]=0;
	vector<ll> Prime;
	for(i=2;i*i<SIZE;i++)
	{
	    if(PrimeNum[i]==1)
	    {
	        for(j=2*i;j<SIZE;j=j+i)
	        {
	            PrimeNum[j]=0;
	        }
	    }
	}
	//
	for(i=2;i<SIZE;i++)
	{
	    if(PrimeNum[i])
	    {
	        Prime.pb(i);
	        //cout<<i<<" ";
	    }
	}
    //printf("\n\nTotal Prime Numbers are : ");
    //cout<<Prime.size()<<endl;
	while(T--)
	{
	    x=31623;
	    cout<<"1 "<<x<<endl;
	    //fflush(stdout);
	    //printf("Enter Query result : ");
	    cin>>Qa;
	    if(Qa==-1)
	    {
	        //printf("Program Terminated.\n");
	        break;
	    }
	    else
	    {
	        //printf("Qa != -1.\n");
	        vector<ll> P;
	        x=x*x;
	        //cout<<"x^2 is : "<<x<<endl;
	        ll temp=x-Qa,PF=0;
	        //cout<<"temp is : "<<temp<<endl;
	        if(isPrime(temp))
	        {
	            //printf("temp=(x^2)-Qa is Prime.\n");
	            cout<<"2 "<<temp<<endl;
	            //fflush(stdout);
	            //printf("Enter Final result : ");
	            cin>>BQa;
	            if(BQa=="No")
	            {
	                //printf("Program terminated.\n");
	                break;
	            }
	        }
	        else
	        {
	            //printf("temp=(x^2) - Qa is not a Prime. Moving to factorise temp.\n");
	            while(temp>1)
	            {
	                //cout<<"Temp is : "<<temp<<" and PF is : "<<PF<<" and Prime number is : "<<Prime[PF]<<endl;
	                if(temp%Prime[PF]==0)
	                {
	                    //cout<<"temp is Divisible by prime : "<<Prime[PF]<<endl;
	                    P.pb(Prime[PF]);
	                    while(temp%Prime[PF]==0)
	                    {
	                        temp/=Prime[PF];
	                    }
	                    //cout<<"temp is completely Divided by the given prime : "<<Prime[PF]<<endl;
	                }
	                PF++;
	                //cout<<"PF incremented to : "<<PF<<endl;
	                if(PF==Prime.size())
                    {
                        break;
                    }
	            }
	            if(isPrime(temp))
                {
                    //cout<<" After loop temp is a prime number: "<<temp<<endl;
                    P.pb(temp);
                }
	            for(temp=0;temp<P.size();temp++)
	            {
	                if(x%P[temp]==Qa)
	                {
	                    break;
	                }
	            }
	            cout<<"2 "<<P[temp]<<endl;
	            //fflush(stdout);
	            //printf("Enter Final result : ");
	            cin>>BQa;
	            if(BQa=="No")
	            {
	                //printf("Program terminated.\n");
	                break;
	            }
	        }
	    }
	}
	return 0;
}
