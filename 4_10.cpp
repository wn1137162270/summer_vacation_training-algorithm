#include<iostream>
using namespace std;

const int maxn=200000+10;
const int INF=1000000001;

int l1[maxn],l2[maxn],r1[maxn],r2[maxn];

int getMax(int x,int y)
{
	return x>y?x:y;
}

int getMin(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int i,n,m,max1=0,min1=INF,max2=0,min2=INF,ans[2];
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		cin>>l1[i]>>r1[i];
	cin>>m;
	for(i=0;i<m;i++)
		cin>>l2[i]>>r2[i];
	for(i=0;i<n;i++)
	{
		max1=getMax(max1,l1[i]);
		min1=getMin(min1,r1[i]);
	}
	for(i=0;i<m;i++)
	{
		max2=getMax(max2,l2[i]);
		min2=getMin(min2,r2[i]);
	}
	ans[0]=max1-min2;
	ans[1]=max2-min1;
	if(ans[0]<0&&ans[1]<0)
		cout<<0<<endl;
	else
		cout<<getMax(ans[0],ans[1])<<endl;
	return 0;
}
