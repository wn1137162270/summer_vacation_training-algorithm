#include<iostream>
#include<vector>
using namespace std;

const int count[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};

int countHexCircle(long long n)
{
	long long d=1,t;
	int i,ans=0;
	vector<long long> vt;
	while(n!=0)
	{
		d*=16;
		t=n%d/(d/16);
		vt.push_back(t);
		n-=n%d;
	}
	for(i=vt.size()-1;i>=0;i--)
		ans+=count[vt[i]];
	return ans;
}

int main()
{
	long long n;
	int ans;
	cin>>n;
	if(n==0)
		ans=1;
	else
		ans=countHexCircle(n);
	cout<<ans<<endl;
	return 0;
}
