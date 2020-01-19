#include <bits/stdc++.h>
#define SizeV 1000000000
using namespace std;
map<int,int> Fib;
int hold;

int last_two(int a)
{
    int i,r,j=1;
    int num=0,dig=0;
    num=a;
    while(num>0)
    {
        num/=10;
        dig++;
    }
    if(dig==1||dig==2)
    {
        return a;
    }
    num=0;
    for(i=1;i<=2;i++)
    {
        r=a%10;
        a=a/10;
        num=num+r*j;
        j=j*10;
    }
    return num;
}

void calc(int N)
{
    if(hold==-1)
    {
        hold=3;
    }
    int i;
    for(i=hold;i<=N;i++)
    {
        Fib[i]=last_two(Fib[i-1]+Fib[i-2]);
    }
    if(N>hold)
    {
        hold=N+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T,N,i;
	hold=-1;
	Fib[1]=1;
    Fib[2]=1;
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    if(Fib[N]==0)
	    {
	        calc(N);
	    }
	    cout<<"Ans : "<<Fib[N]<<endl;
	}
	return 0;
}
