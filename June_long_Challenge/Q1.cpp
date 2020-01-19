#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int T,i,D,ndP,AP,ans;
	string Proxy;
//	printf("Enter T :");
	scanf("%d",&T);
	while(T--)
	{
	    ndP=0;
	    ans=0;
	    printf("E D :");
	    scanf("%d",&D);
	  //  printf("E String :");
	    cin>>Proxy;
	    for(i=0;i<D;i++)
	    {
	        if(Proxy[i]=='P')
	        {
	            ndP++;
	        }
	    }
	  //  printf("Initially ndP=%d\n",ndP);
	    AP=(ndP*100)/D;
	 //   printf("Initially AP=%d\n",AP);
	    if(AP<75)
	    {
	    //	printf("AP=%d <75.\n",AP);
	        for(i=2;i<D-2;i++)
	        {
	            if(Proxy[i]=='A'&&(Proxy[i-1]=='P'||Proxy[i-2]=='P')&&(Proxy[i+1]=='P'||Proxy[i+2]=='P'))
	            {
	                ndP++;
	                ans++;
	            }
	            AP=(ndP*100)/D;
	            if(AP>=75)
	            {
	            //	printf("Got AP>=75 AP=%d ong to break from the loop\n",AP);
	                break;
	            }
	        }
	    }
	    if(AP<75)
	    {
	    //	printf("Printing Result Ap=%d\n",AP);
	        printf("-1\n");
	    }
	    else
	    {
	        printf("%d\n",ans);
	    }
	}
	return 0;
}

