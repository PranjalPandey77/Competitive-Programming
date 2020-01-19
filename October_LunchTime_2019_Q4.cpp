/*
Author : Pranjal Pandey
IT 3rd Year
MNNIT Allahabad
*/

#include<bits/stdc++.h>

typedef long long ll;

#define SIZE 2000000

using namespace std;

int N,B[SIZE],A[SIZE],temp[SIZE];

ll Merge(int l,int m,int r)
{
    int i,j,k;
    ll inv_cnt=0;
    i=l;
	j=m;
	k=l;
    while((i<=m-1)&&(j<=r))
    {
        if(B[i]<=B[j])
        {
            temp[k++]=B[i++];
        }
        else
        {
            temp[k++]=B[j++];
            inv_cnt=inv_cnt+(m-i);
        }
    }
    while(i<=m-1)
    {
        temp[k++]=B[i++];
    }
    while(j<=r)
    {
        temp[k++]=B[j++];
    }
    for(i=l;i<=r;i++)
    {
        B[i]=temp[i];
    }
    return inv_cnt;
}

ll mergeSort(int l,int r)
{
    int m;
    ll inv_cnt=0;
    if(l<r)
    {
        m=(r+l)/2;
        inv_cnt=mergeSort(l,m);
        inv_cnt+=mergeSort(m+1,r);
        inv_cnt+=Merge(l,m+1,r);
    }
    return inv_cnt;
}

int main()
{
    int T,i,Q,K;
    cout<<"Enter T : ";
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        for(i=0;i<N;i++)
        {
            cin>>A[i];
        }
        while(Q--)
        {
            cin>>K;
            for(i=0;i<N;i++)
            {
                B[i]=A[i]^K;
            }
            cout<<mergeSort(0,N-1)<<endl;
        }
    }
    return 0;
}
