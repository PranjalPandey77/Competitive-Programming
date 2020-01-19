#include<bits/stdc++.h>

#define pii pair<int,int>
#define F first
#define S second

using namespace std;

int main()
{
    int N,i,X,sum,cnt=0;
    printf("Enter N and Average : ");
    cin>>N>>X;
    int A[N];
    for(i=0;i<N;i++)
    {
        printf("Enter Element : ");
        cin>>A[i];
    }
    sum=0;
    pii Ans(-1,-1),temp(-1,-1);
    for(i=0;i<N;i++)
    {
        sum+=A[i];
        cnt++;
        if(temp.F==-1)
        {
            temp.F=i;
        }
        if(sum/cnt>=X&&temp.F!=-1)
        {
            if(Ans.F==-1&&Ans.S==-1)
            {
                Ans.F=temp.F;
                Ans.S=i;
                temp.S=i;
            }
            else
            if((i-temp.F+1)>(Ans.S-Ans.F+1))
            {
                Ans.F=temp.F;
                Ans.S=i;
                temp.S=i;
            }
        }
        if(sum<0)
        {
            sum=0;
            cnt=0;
            temp.F=-1;
        }
    }

    if(Ans.F==-1&&Ans.S==-1)
    {
        printf("Starting and ending point are not defined.\n");
    }
    else
    {
        printf("Starting and ending point are : ");
        cout<<Ans.F<<" "<<Ans.S<<endl;
    }
    return 0;
}
