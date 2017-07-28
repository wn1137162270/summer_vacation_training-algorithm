#include<cstdio>
#include<cmath>

int main()
{
	int i,n,h;
	double ans;
	scanf("%d %d",&n,&h);
	for(i=1;i<n-1;i++)
	{
		ans=sqrt(i)*h/sqrt(n);
		printf("%.12lf ",ans);
	}
	ans=sqrt(i)*h/sqrt(n);
	printf("%.12lf\n",ans);
	return 0;
}
