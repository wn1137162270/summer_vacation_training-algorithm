#include<iostream>
using namespace std;

const int maxn=100000+5;

int main()
{
	int n,k,w[maxn],i,count=0;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(i=0;i<n;i++)
	{
		if(w[i]%k==0)
		{
			count+=w[i]/k;
		}
		else
		{
			count+=w[i]/k+1;
		}
	}
	if(count%2==0)
	{
		cout<<count/2<<endl;
	}
	else
	{
		cout<<count/2+1<<endl;
	}
	return 0;	
} 
