#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int T,N,i;
    //printf("Enter TC : ");
    scanf("%d",&T);
    while(T--)
    {
        cin>>N;
        map<int,int> Mp;
        int ar[N];
        for(i=0;i<N;i++)
        {
            cin>>ar[i];
        }
        if(N==4)
        {
            int D1=ar[1]-ar[0];
            int D2=ar[2]-ar[1];
            int D3=ar[3]-ar[2];
            if(D2==D3&&D2!=D1)
            {
                ar[0]=ar[1]-D2;
            }
            else
            if(D2==D1&&D3!=D1)
            {
                ar[N-1]=ar[N-2]+D2;
            }
            else
            {
                int temp=ar[1];
                ar[1]=ar[0]+D3;
                if(ar[1]-ar[0]==ar[3]-ar[2]&&ar[1]-ar[0]==ar[2]-ar[1])
                {

                }
                else
                {
                    ar[1]=temp;
                    ar[2]=ar[1]+D1;
                    if(ar[1]-ar[0]==ar[3]-ar[2]&&ar[1]-ar[0]==ar[2]-ar[1])
                    {

                    }
                }
            }
            for(i=0;i<4;i++)
            {
                printf("%d ",ar[i]);
            }
        }
        else
        {
            vector<int> diff;
            int Max,D,fg=-1;
            for(i=1;i<N;i++)
            {
                if(Mp[ar[i]-ar[i-1]]==0)
                {
                    diff.pb(ar[i]-ar[i-1]);
                    Mp[ar[i]-ar[i-1]]++;
                    if(fg==-1)
                    {
                        Max=1;
                        D=ar[i]-ar[i-1];
                        fg++;
                    }
                    else
                    {
                        if(Max<Mp[ar[i]-ar[i-1]])
                        {
                            Max=Mp[ar[i]-ar[i-1]];
                            D=ar[i]-ar[i-1];
                        }
                    }
                }
                else
                {
                    Mp[ar[i]-ar[i-1]]++;
                    if(fg==-1)
                    {
                        Max=1;
                        D=ar[i]-ar[i-1];
                        fg++;
                    }
                    else
                    {
                        if(Max<Mp[ar[i]-ar[i-1]])
                        {
                            Max=Mp[ar[i]-ar[i-1]];
                            D=ar[i]-ar[i-1];
                        }
                    }
                }
            }
            fg=0;
            int ind=-1;
           // printf("D : %d Max : %d\n",D,Max);
            for(i=1;i<N;i++)
            {
                if((ar[i]-ar[i-1])!=D)
                {
                    fg++;
                    ind=i;
                }
            }
            if(fg==1)
            {
               // printf("ind: %d\n",ind);
                if(ar[1]-ar[0]!=D)
                {
                    ar[0]=ar[1]-D;
                }
                else
                if(ar[N-1]-ar[N-2]!=D)
                {
                    ar[N-1]=ar[N-2]+D;
                }
            }
            else
            if(fg==2)
            {
               // printf("ind: %d\n",ind);
                ar[ind-1]=ar[ind-2]+D;
            }






            for(i=0;i<N;i++)
            {
                cout<<ar[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
