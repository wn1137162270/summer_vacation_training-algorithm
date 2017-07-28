#include<cstdio>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n%3==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;	
} 
