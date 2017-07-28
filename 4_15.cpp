#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100000+10;

struct node
{
	int b,p;
	bool operator <(const node &nd)const
	{
		if(p<nd.p||(p==nd.p&&b>nd.b))
			return true;
		return false;
	}
};

node fta[maxn],ftb[maxn];
int maxa1[maxn],maxa2[maxn],maxb1[maxn],maxb2[maxn],indexa1[maxn],indexb1[maxn];

int getMax(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int i,j=0,k=0,n,c,d,b,p,t,temp[4],max1=0,max2=0,max0=0,maxa=0,maxb=0,max=0;
	char ch;
	ios::sync_with_stdio(false);
	cin>>n>>c>>d;
	for(i=0;i<n;i++)
	{
		cin>>b>>p>>ch;
		if(ch=='C')
		{
			fta[j].b=b;
			fta[j].p=p;
			j++;
		}
		else
		{
			ftb[k].b=b;
			ftb[k].p=p;
			k++;
		}
	}
	memset(maxa1,0,sizeof(maxa1));
	memset(maxa2,0,sizeof(maxa2));
	memset(maxb1,0,sizeof(maxb1));
	memset(maxb2,0,sizeof(maxb2));
	sort(fta,fta+j);
	sort(ftb,ftb+k);
	t=0;
	for(i=0;i<j;i++)
	{
		if(t!=fta[i].p)
		{
			maxa1[fta[i].p]=fta[i].b;
			indexa1[fta[i].p]=i;
			t=fta[i].p;
		}
	}
	t=0;
	for(i=0;i<j;i++)
	{
		if(t!=fta[i].p&&i+1<j&&fta[i+1].p==fta[i].p)
		{
			maxa2[fta[i].p]=fta[i+1].b;
			t=fta[i].p;
		}
	}
	for(i=1;i<maxn;i++)
	{
		temp[0]=maxa1[i];
		temp[1]=maxa2[i];
		temp[2]=maxa1[i-1];
		temp[3]=maxa2[i-1];
		sort(temp,temp+4); 
		maxa2[i]=temp[2];
	}
	for(i=1;i<maxn;i++)
	{
		maxa1[i]=getMax(maxa1[i],maxa1[i-1]);
		if(maxa1[i]<maxa1[i-1])
			indexa1[i]=indexa1[i-1];
	}
	t=0;
	for(i=0;i<k;i++)
	{
		if(t!=ftb[i].p)
		{
			maxb1[ftb[i].p]=ftb[i].b;
			indexb1[ftb[i].p]=i;
			t=ftb[i].p;
		}
	}
	t=0;
	for(i=0;i<k;i++)
	{
		if(t!=ftb[i].p&&i+1<k&&ftb[i+1].p==ftb[i].p)
		{
			maxb2[ftb[i].p]=ftb[i+1].b;
			t=ftb[i].p;
		}
	}
	for(i=1;i<maxn;i++)
	{
		temp[0]=maxb1[i];
		temp[1]=maxb2[i];
		temp[2]=maxb1[i-1];
		temp[3]=maxb2[i-1];
		sort(temp,temp+4); 
		maxb2[i]=temp[2];
	}
	for(i=1;i<maxn;i++)
	{
		maxb1[i]=getMax(maxb1[i],maxb1[i-1]);
		if(maxb1[i]<maxb1[i-1])
			indexb1[i]=indexb1[i-1];
	}
	for(i=0;i<100;i++)
	{
		cout<<i<<maxa1[i]<<' '<<maxa2[i]<<' '<<maxb1[i]<<' '<<maxb2[i]<<endl;
	}
	for(i=0;i<=c/2;i++)
	{
		if(maxa1[i]>0&&maxa1[c-i]>0)
		{
			if(indexa1[i]!=indexa1[c-i])
				max1=getMax(max1,maxa1[i]+maxa1[c-i]);
			else if(maxa2[c-i]>0)
				max1=getMax(max1,maxa1[i]+maxa2[c-i]);
		}
	}
	for(i=0;i<=d/2;i++)
	{
		if(maxb1[i]>0&&maxb1[d-i]>0)
		{
			if(indexb1[i]!=indexb1[d-i])
				max2=getMax(max2,maxb1[i]+maxb1[d-i]);
			else if(maxb2[d-i]>0)
				max2=getMax(max2,maxb1[i]+maxb2[d-i]);
		}
	}
	for(i=0;i<j;i++)
		if(fta[i].p<=c)
			maxa=getMax(maxa,fta[i].b);
	for(i=0;i<k;i++)
		if(ftb[i].p<=d)
			maxb=getMax(maxb,ftb[i].b);
	cout<<max1<<' '<<max2<<' '<<maxa<<' '<<maxb<<endl;
	if(maxa>0&&maxb>0)
		max0=maxa+maxb;
	max=getMax(max0,max1);
	max=getMax(max,max2);
	cout<<max<<endl;
	return 0;
}
