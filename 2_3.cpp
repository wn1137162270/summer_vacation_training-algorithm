#include<iostream>
#include<cstring>
using namespace std;

const int maxn=32768+5;
long long d[maxn];

long long dp(int x)
{
	int i;
	if(d[x]>0)
		return d[x];
	for(i=1;i<=3;i++)
	{
		if(x>=i)
			d[x]+=dp(x-i);
	}
	return d[x];
}

int main()
{
	int n;
	long long ans;
	cin>>n;
	memset(d,0,sizeof(d));
	d[0]=1;
	ans=dp(n);
	cout<<ans<<endl;
	return 0;
}
