#include<iostream>
using namespace std;

int getDecimal(long long n)
{
	long long d;
	int count=0;
	while(n!=0)
	{
		d=n%10;
		n=n/10;
		count++;
	}
	return count;
}

int main()
{
	long long n,o,d;
	int k,w=0,count=0;
	cin>>n>>k;
	o=n;
	while(n!=0)
	{
		d=n%10;
		n=n/10;
		if(d==0)
		{
			count++;
			if(count==k)
				break;
		}
		else
		{
			w++;
		}
	}
	if(count==k)
		cout<<w<<endl;
	else if(o!=0)
		cout<<getDecimal(o)-1<<endl;
	else 
		cout<<0<<endl;
	return 0;	
} 
