#include<iostream>
using namespace std;

int main()
{
	int len,i,n;
	long long ans;
	while(cin>>n)
	{
		ans=0;
		len=n/3;
		for(i=0;i<=len;i++)
			ans+=(n-i*3)/2+1;
		cout<<ans<<endl;
	}
}
