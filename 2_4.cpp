#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000+5;

int getMax(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int i,j,n,a[maxn],dp[maxn],ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(a[j]<a[i])
				dp[i]=getMax(dp[i],dp[j]+1);
		}
	}
	for(i=1;i<=n;i++)
	{
		//cout<<dp[i]<<endl;
		ans=getMax(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;	
}
//ע��memset����ʵ���Ƕ�ÿ���ֽڸ�ֵ����˶��ڳ�char����֮�������ֻ�ܳ�ʼ��Ϊ0�����ܳ�ʼ��Ϊ����ֵ�� 
