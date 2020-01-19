#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num,iter,fg=1;
	scanf("%d",&num);
	int TreeNode[num+100];
	for(iter=0;iter<num;iter++)
	{
		scanf("%d",&TreeNode[iter]);
	}
	sort(TreeNode,TreeNode+num);
	for(iter=num-2;iter>=0;iter--)
	{
		if(TreeNode[iter]!=TreeNode[num-1])
		{
			fg=0;
			printf("%d",TreeNode[iter]);
			break;
		}
	}
	if(fg==1)
	{
		printf("0");
	}
	return 0;
}
