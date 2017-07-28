#include<cstdio>
#include<cstring>

const int maxn=10000+5;
double dp[maxn];

double getMin(double x,double y)
{
	return x<y?x:y;
}

int main()
{
	int i,j,n,m,v;
	double w,ans;
	scanf("%d %d",&n,&m);
	while(n||m)
	{	
		for(i=0;i<=n;i++)
			dp[i]=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d %lf",&v,&w);
			for(j=n;j>=0;j--)
			{
				if(j>=v)
					dp[j]=getMin(dp[j],dp[j-v]*(1-w));
			}
		}
		ans=(1-dp[n])*100;
		printf("%.1lf%%\n",ans);
		scanf("%d %d",&n,&m);
	}
	return 0;
}
