#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,R,C,i,j,k;
	printf("Enter TC :");
	cin>>T;
	while(T--)
	{
	    cin>>R>>C;
	    int Gd[R][C],TGd[R][C];
	    memset(Gd,0,sizeof(Gd));
	    memset(TGd,0,sizeof(TGd));
	    char ch;
	    long long ans=0;
	    for(i=0;i<R;i++)
	    {
	        for(j=0;j<C;j++)
	        {
	            cin>>ch;
	            Gd[i][j]=(int)ch;

	        }
	    }
	    int Hash[R][C];
	    memset(Hash,0,sizeof(Hash));
	    for(i=1;i<max(R,C);i++)
	    {
	        for(j=0;j<R;j++)
            {
                for(k=0;k<C;k++)
                {
                    TGd[j][k]=Gd[j][k];
                }
            }
	        for(j=0;j<R;j++)
	        {
	            for(k=0;k<C;k++)
	            {
	                if(Gd[j][k]!=45&&Gd[j][k]!='35')
	                {
	                    switch(Gd[j][k])
	                    {
	                        case 68 :
	                        {
	                            if(j==R-1)
	                            {
	                                TGd[j][k]=45;
	                            }
	                            else
	                            {
	                                if(!Gd[j+1][k]==35)
	                                {
	                                    Hash[j+1][k]++;
	                                    TGd[j+1][k]=68;
	                                    TGd[j][k]=45;
	                                }
	                                else
	                                {
	                                    TGd[j+1][k]=35;
	                                    TGd[j][k]=45;
	                                }
	                            }
	                            break;
	                        }
	                        case 76 :
	                        {
	                            if(k==0)
	                            {
	                                TGd[j][k]=45;
	                            }
	                            else
	                            {
	                                if(!Gd[j][k-1]==35)
	                                {
	                                    Hash[j][k-1]++;
	                                    TGd[j][k-1]=76;
	                                    TGd[j][k]=45;
	                                }
	                                else
	                                {
	                                    TGd[j][k-1]=35;
	                                    TGd[j][k]=45;
	                                }
	                            }
	                            break;
	                        }
	                        case 82 :
	                        {
	                            if(k==C-1)
	                            {
	                                TGd[j][k]=45;
	                            }
	                            else
	                            {
	                                if(!Gd[j][k+1]==35)
	                                {
	                                    Hash[j][k+1]++;
	                                    TGd[j][k+1]=82;
	                                    TGd[j][k]=45;
	                                }
	                                else
	                                {
	                                    TGd[j][k+1]=35;
	                                    TGd[j][k]=45;
	                                }
	                            }
	                            break;
	                        }
	                        case 85 :
	                        {
	                            if(j==0)
	                            {
	                                TGd[j][k]=45;
	                            }
	                            else
	                            {
	                                if(!Gd[j-1][k]==35)
	                                {
	                                    Hash[j-1][k]++;
	                                    TGd[j-1][k]=85;
	                                    TGd[j][k]=45;
	                                }
	                                else
	                                {
	                                    TGd[j-1][k]=35;
	                                    TGd[j][k]=45;
	                                }
	                            }
	                            break;
	                        }
	                    }
	                }
	            }
	        }

            for(j=0;j<R;j++)
	        {
                for(k=0;k<C;k++)
                {
                    if(TGd[j][k]==0)
                    {
                        Gd[j][k]=45;
                    }
                    else
                    {
                        Gd[j][k]=TGd[j][k];
                    }
                    TGd[j][k]=0;
                }
            }

	        for(j=0;j<R;j++)
	        {
	            for(k=0;k<C;k++)
	            {
	                if(Hash[j][k]>1)
	                {
	                    ans+=((Hash[j][k]*(Hash[j][k]-1))/2);
	                }
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
