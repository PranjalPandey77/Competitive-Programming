#include<bits/stdc++.h>
using namespace std;
#define SizeV 10000
long long A[SizeV],B[SizeV];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,N,X,i,M,SM,ans;
    cin>>T;
    while(T--)
    {
        cin>>N>>X;
        M=0;
        SM=0;
        vector<int> Mv;
        for(i=0;i<N;i++)
        {
            cin>>A[i];
            B[i]=A[i];
        }
        int fg=-1;
        for(i=0;i<N-1;i++)
        {
            if(A[i]+X<2*X)
            {
                M++;
                B[i+1]+=B[i]
                if(fg==i-1)
                {
                    Mv.pop_back();
                    Mv.push_back(B[i+1]);
                }
                else
                {
                    Mv.push_back(B[i]);
                }
            }
            fg=i;
        }
       /* printf("Mv vector is : ");
        for(i=0;i<Mv.size();i++)
        {
            printf("%d ",Mv[i]);
        }
        printf("\n");*/
        if(M>(N-M))
        {
            int tm=0;
            sort(Mv.begin(),Mv.end());
            for(i=0;i<Mv.size();i++)
            {
                if(tm<=(N-M))
                {
                    SM+=Mv[i];
                }
            }
            ans=(SM+M*X);
            printf("%d\n",ans);
        }
        else
        if(M==(N-M))
        {
            for(i=0;i<Mv.size();i++)
            {
                SM+=Mv[i];
            }
            ans=(SM+(M*X));
            printf("%d\n",ans);
        }
        else
        {
            for(i=0;i<Mv.size();i++)
            {
                SM+=Mv[i];
            }
            ans=(SM+(N-M)*X);
            printf("%d\n",ans);
        }
    }
    return 0;
}
