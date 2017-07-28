#include<iostream>
using namespace std;

const int maxn=100000+5;
const int INFMIN=-1000000001;

int getMax(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int n,i,a[maxn],ev[maxn],od[maxn],ans=INFMIN;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=0;i<=n;i++)
	{
		ev[i]=INFMIN;
		od[i]=INFMIN;
	}
	for(i=1;i<=n;i++)
	{
		if(!(a[i]%2))
		{
			ev[i]=a[i];
			if(ev[i-1]!=INFMIN)
			{
				ev[i]=getMax(ev[i],ev[i-1]);
				ev[i]=getMax(ev[i],ev[i-1]+a[i]);
			}
			if(od[i-1]!=INFMIN)
			{
				od[i]=getMax(od[i-1],od[i-1]+a[i]);
			}
		}
		else
		{
			od[i]=a[i];
			if(od[i-1]!=INFMIN)
			{
				od[i]=getMax(od[i],od[i-1]);
				ev[i]=getMax(ev[i],od[i-1]+a[i]);
			}
			if(ev[i-1]!=INFMIN)
			{
				od[i]=getMax(od[i],ev[i-1]+a[i]);
				ev[i]=getMax(ev[i],ev[i-1]);
			}
		}
	} 
	for(i=1;i<=n;i++)
		ans=getMax(ans,od[i]);
	cout<<ans<<endl;
	return 0;
}
