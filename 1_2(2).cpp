#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

const int maxm=100000+5;
long long a[maxm];
int m;

bool inquireBad(long long number)
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
	int i,count=0;
	long long b,q,l;
	cin>>b>>q>>l>>m;
	for(i=0;i<m;i++)
		cin>>a[i];
	if(b==0)
	{
		if(inquireBad(0))
			count=0;
		else
			count=-1;
	}
	else if(q==0)
	{
		if(inquireBad(0)&&inquireBad(b))
			count=0;
		else if(inquireBad(0)&&!inquireBad(b)&&abs(b)<=l)
			count=1;
		else if(inquireBad(0)&&!inquireBad(b)&&abs(b)>l)
			count=0;
		else if(!inquireBad(0)&&abs(b)<=l)
			count=-1;
		else
			count=0;
	}
	else if(q==1)
	{
		if(inquireBad(b))
			count=0;
		else if(abs(b)<=l)
			count=-1;
		else
			count=0;
	}
	else if(q==-1)
	{
		if(inquireBad(b)&&inquireBad(-b))
			count=0;
		else if(abs(b)<=l)
			count=-1;
		else
			count=0;
	}
	else
	{
		while(abs(b)<=l)
		{
			if(!inquireBad(b))
				count++;
			b*=q;
		}
	}
	if(count==-1)
		cout<<"inf"<<endl;
	else
		cout<<count<<endl;
	return 0;
}
