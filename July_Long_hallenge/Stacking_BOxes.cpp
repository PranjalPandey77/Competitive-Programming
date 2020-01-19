#define pb push_back
#define mt make_tuple
#define tiii tuple<int,int,int>

bool comp(const tiii &A,const tiii &B)
{
    return (get<0>(A))>(get<0>(B));
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector < tiii > B;
    int i,j;
    for(i=0;i<n;i++)
    {
        B.pb(mt(length[i]*width[i],max(length[i],width[i]),height[i]));
        B.pb(mt(height[i]*width[i],max(height[i],width[i]),length[i]));
        B.pb(mt(length[i]*height[i],max(length[i],height[i]),width[i]));
    }
    sort(B.begin(),B.end(),comp);
    int Ht[3*n];
    for(i=0;i<3*n;i++)
    {
        Ht[i]=get<2>(B[i]);
    }
    for(i=1;i<3*n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((get<1>(B[i])>get<1>(B[j]))&&(((get<0>(B[i]))/(get<1>(B[i])))>((get<0>(B[j]))/(get<1>(B[j])))))
            {
                Ht[i]=max(Ht[i],Ht[i]+(get<2>(B[i])));
            }
        }
    }
    int ans=Ht[0];
    for(i=1;i<3*n;i++)
    {
        if(ans<Ht[i])
        {
            ans=Ht[i];
        }
    }
    return ans;
}
