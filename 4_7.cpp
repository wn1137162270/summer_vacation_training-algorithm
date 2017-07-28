#include<cstdio>

const int maxn=60000+10;
const double INF=1000000000;
const double eps=0.00000001;

struct person
{
	int x,v;
};

int n;
person friends[maxn];

double getMax(double x,double y)
{
	return x>y?x:y;
}

double getMin(double x,double y)
{
	return x<y?x:y;
}

int judge(double t)
{
	int i;
	double l=-INF,r=INF;
	for(i=0;i<n;i++)
	{
		l=getMax(l,friends[i].x-friends[i].v*t);
		r=getMin(r,friends[i].x+friends[i].v*t);
		if(r<l)
			return 0;
	}
	return 1;
}

int main()
{
	int i,ret;
	double l=0,r=INF,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&friends[i].x);
	for(i=0;i<n;i++)
		scanf("%d",&friends[i].v);
	while(r-l>eps)
	{
		m=(l+r)/2;
		ret=judge(m);
		if(ret)
			r=m;
		else
			l=m;
	}
	printf("%.9lf\n",(l+r)/2);
	return 0;	
} 
