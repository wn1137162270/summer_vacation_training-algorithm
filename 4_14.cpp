#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=300000+10;

int main()
{
	int i,n,p[maxn];
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i];
	sort(p,p+n);
	if(n%2)
		cout<<p[n/2]<<endl;
	else
		cout<<p[(n-1)/2]<<endl;
	return 0;
}
