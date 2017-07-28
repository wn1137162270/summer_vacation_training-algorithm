#include<cstdio>
#include<cmath>
#include<cstdlib>

const int maxn=100000+5;
int m;
long long a[maxn];

bool inquireBad(int number)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(a[i]==number)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	long long b1,q,l;
	int i,count=0;
	scanf("%lld %lld %lld %d",&b1,&q,&l,&m);
	for(i=0;i<m;i++)
		scanf("%lld",&a[i]);
	if(b1==0||b1==1)
	{
		if(inquireBad(b1))
		{
			count=0;
		}
		else
		{
			count=-1;
		}
	}
	else if(b1==-1)
	{
		if(q%2==0)
		{
			if(inquireBad(1)&&inquireBad(-1))
			{
				count=0;
			}
			else if(inquireBad(1)&&!inquireBad(-1))
			{
				count=1;
			}
			else 
			{
				count=-1;
			}
		}
		else
		{
			if(inquireBad(b1))
			{
				count=0;
			}
			else
			{
				count=-1;
			}
		}
	}
	else if(q==0)
	{
		if(inquireBad(1)&&inquireBad(b1))
		{
			count=0;
		}
		else if(inquireBad(1)&&!inquireBad(b1)&&abs(b1)<=l)
		{
			count=1;
		}
		else if(inquireBad(1)&&!inquireBad(b1)&&abs(b1)>l)
		{
			count=0;
		}
		else 
		{
			count=-1;
		}
	}
	else if(q==1)
	{
		if(inquireBad(b1))
		{
			count=0;
		}
		else if(abs(b1)<=l)
		{
			count=-1;
		}
		else
		{
			count=0;
		}
	}
	else if(q<=-1)
	{
		count=0;
	}
	else
	{
		while(abs(b1)<=l)
		{
			if(!inquireBad(b1))
				count++;
			b1=pow(b1,q);
			printf("b1:%lld\n",b1);
		}
	}
	if(count==-1)
		printf("inf\n");
	else
		printf("%d\n",count);
	return 0;
}
