#include<iostream>
using namespace std;

const int maxn=20+5;

int main()
{
	int i,j,n,k,flag,ans[maxn];
	cin>>n>>k;
	for(i=1;i<=k-1;i++)
	{
		flag=0;
		for(j=2;j<n;j++)
		{
			if(n%j==0)
			{
				n=n/j;
				ans[i]=j;
				flag=1; 
				break;
			} 
		}
		if(flag==0)
			break;
	}
	if(k==1)
		cout<<n<<endl;
	else if(!flag)
		cout<<-1<<endl;
	else
	{
		for(i=1;i<k;i++)
			cout<<ans[i]<<' ';
		cout<<n<<endl;
	}
	return 0;
}
