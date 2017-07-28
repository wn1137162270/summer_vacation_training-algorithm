#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000+10;

int main()
{
	int i,n,num1[10],num2[10],ts1=0,ts2=0;
	char s1[maxn],s2[maxn];
	cin>>n>>s1>>s2;
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	for(i=0;i<n;i++)
	{
		num1[s1[i]-'0']++;
		num2[s2[i]-'0']++;
	}
	for(i=0;i<10;i++)
	{
		ts1+=num1[i];
		if(ts1>=num2[i])
			ts1-=num2[i];
		else
			ts1=0;
	}
	for(i=0;i<9;i++)
	{
		ts2+=num1[i];
		if(ts2>=num2[i+1])
			ts2-=num2[i+1];
		else
			ts2=0;
	}
	ts2+=num1[9];
	ts2=n-ts2;
	cout<<ts1<<endl;
	cout<<ts2<<endl;
	return 0;
}
