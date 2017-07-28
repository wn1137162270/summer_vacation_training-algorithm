#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

const int maxn=100000+5;

long long getMin(long long x,long long y)
{
	return x<y?x:y; 
}

int main()
{
	int i,n,flag=0;
	long long k,a[maxn],count=0,min;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	min=a[0];
	for(i=0;i<n-1;i++)
	{
		if(abs(a[i+1]-a[i])%k)
		{
			flag=1;
			break;	
		}
		min=getMin(min,a[i]);
	}
	min=getMin(min,a[n-1]);
	for(i=0;i<n;i++)
		count+=(a[i]-min)/k;
	if(flag==1)
		cout<<"-1"<<endl;
	else
		cout<<count<<endl;
	return 0; 
} 
