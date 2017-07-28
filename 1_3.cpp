#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

const int maxn=100000+5;
long long a[maxn],b[maxn],c[maxn];

long long getMax(long long x,long long y)
{
	return x>y?x:y;
}

long long getMin(long long x,long long y)
{
	return x<y?x:y;
}

long long maxsum(int l,int r)
{
	int m,i,k=0,fa=0,fi=0;
	long long lm,rm,mma,mmi,mm,temp,lmma,lmmi,rmma,rmmi,rlm;
	if(r-l==1)	
		return b[l];
	m=l+(r-l)/2;
	//cout<<"l:"<<l<<" m:"<<m<<" r:"<<r<<endl;
	lm=maxsum(l,m);
	rm=maxsum(m,r);
	temp=0;
	for(i=m-1;i>=l;i--)
	{
		temp=temp+c[i];
		if(i%2==0)
		{
			if(k/2==0)
			{
				lmma=temp;
				fa=1;
			}
			lmma=getMax(lmma,temp);
		}
		else
		{
			if(k/2==0)
			{
				lmmi=temp;
				fi=1;
			} 
			lmmi=getMin(lmmi,temp);
		}
		k++;
	}
	//cout<<"lmma:"<<lmma<<" lmmi:"<<lmmi<<endl;
	temp=0;
	rmma=c[m];
	rmmi=c[m];
	for(i=m;i<r;i++)
	{
		temp=temp+c[i];
		rmma=getMax(rmma,temp);
		rmmi=getMin(rmmi,temp);
	}
	//cout<<"rmma:"<<rmma<<" rmmi:"<<rmmi<<endl;
	if(fa&&!fi)
		mm=lmma+rmma;
	else if(!fa&&fi)
		mm=-(lmmi+rmmi);
	else if(fa&&fi)
		mm=getMax(lmma+rmma,-(lmmi+rmmi));
	//cout<<"mm:"<<mm<<endl;
	rlm=getMax(lm,rm);
	//cout<<"lm:"<<lm<<" rm:"<<rm<<endl;
	return getMax(rlm,mm);
}

int main()
{
	int n,i;
	long long max;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
		b[i]=abs(a[i]-a[i+1]);
	for(i=0;i<n-1;i++)
	{
		if(i%2==0)
			c[i]=b[i];
		else
			c[i]=-b[i];
	}
//	for(i=0;i<n-1;i++)
//		cout<<c[i]<<endl;
	max=maxsum(0,n-1);
	cout<<max<<endl;
	return 0;
}
