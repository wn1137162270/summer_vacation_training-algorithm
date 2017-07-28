#include<cstdio>

const int maxn=10000+5;

int main()
{
	int i,k,flag,s[maxn],t;
	long long a[maxn],dp[maxn],max;
	scanf("%d",&k);
	while(k)
	{
		flag=0;
		for(i=1;i<=k;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=0)
				flag=1;
		}
		dp[0]=0;
		s[0]=1;
		if(!flag)
		{
			printf("0 %lld %lld\n",a[1],a[k]);
		}
		else
		{
			for(i=1;i<=k;i++)
			{
				if(a[i]>a[i]+dp[i-1])
				{
					s[i]=i;
					dp[i]=a[i];
				}
				else
				{
					s[i]=s[i-1];
					dp[i]=a[i]+dp[i-1];
				}
			}
			max=-1;
			for(i=1;i<=k;i++)
			{
				if(dp[i]>max)
				{
					max=dp[i];
					t=i;
				}	
			}
			printf("%lld %lld %lld\n",max,a[s[t]],a[t]);
		}
		scanf("%d",&k);
	}
	return 0;	
} 
