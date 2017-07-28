#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10000+10;

int main()
{
	int i,j,n,m,k,t,f,flag=0;
	bool visa[maxn],visb[maxn];
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		f=0;
		memset(visa,false,sizeof(visa));
		memset(visb,false,sizeof(visb));
		cin>>k;
		for(j=0;j<k;j++)
		{
			cin>>t;
			if(t>0)
			{
				if(visb[t])
					f=1;
				else
					visa[t]=true;
			}
			else
			{
				if(visa[-t])
					f=1;
				else
					visb[-t]=true;
			}
		}
		if(f==0)
			flag=1;
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
