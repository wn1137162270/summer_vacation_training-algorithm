#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

const int maxn=100000+10;

int main()
{
	int i,j,n,m,flag=0;
	bool vis[maxn];
	memset(vis,false,sizeof(vis));
	cin>>n;
	m=sqrt(n+1);
	for(i=2;i<=m;i++)
		if(!vis[i])
			for(j=i*i;j<=n+1;j+=i)
				vis[j]=true;
	for(i=2;i<=n+1;i++)
		if(vis[i])
		{
			flag=1;
			break;
		}
	if(flag)
		cout<<2<<endl;
	else
		cout<<1<<endl;
	for(i=2;i<=n+1;i++)
	{	
		if(i==n+1)
		{
			if(vis[i])
				cout<<2<<endl;
			else
				cout<<1<<endl;
		} 
		else
		{
			if(vis[i])
				cout<<2<<' ';
			else
				cout<<1<<' ';
		}
	}
	return 0;	
} 
