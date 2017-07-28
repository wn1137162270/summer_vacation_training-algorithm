#include<iostream>
#include<map>
#include<string> 
using namespace std;

const int maxn=5000+10;
const int maxm=1000+10;

int n,val[maxn][maxm],kind[maxn],op1[maxn],op2[maxn],mmax[maxm],mmin[maxm];

int cal(int j)
{
	int i,s=0;
	for(i=1;i<=n;i++)
	{
		if(kind[i]==1)	val[i][j]=val[op1[i]][j]&val[op2[i]][j];
		if(kind[i]==2)	val[i][j]=val[op1[i]][j]|val[op2[i]][j];
		if(kind[i]==3)	val[i][j]=val[op1[i]][j]^val[op2[i]][j];
		s+=val[i][j];
	}
	return s;
}

int main()
{
	int i,j,m,s0,s1;
	string str;
	map<string,int> index;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	index["?"]=0;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		index[str]=i;
		cin>>str;
		cin>>str;
		if(str[0]=='0'||str[0]=='1')
		{
			kind[i]=0;
			for(j=0;j<m;j++)
				val[i][j]=str[j]-'0';
		}
		else
		{
			op1[i]=index[str];
			cin>>str;
			if(str[0]=='A')
				kind[i]=1;
			else if(str[0]=='O')
				kind[i]=2;
			else
				kind[i]=3;
			cin>>str;
			op2[i]=index[str];
		}
	}
	for(j=0;j<m;j++)
	{
		val[0][j]=0;
		s0=cal(j);
		val[0][j]=1;
		s1=cal(j);
		if(s0>=s1)
			mmax[j]=0;
		else
			mmax[j]=1;
		if(s0<=s1)
			mmin[j]=0;
		else
			mmin[j]=1;
	}
	for(i=0;i<m;i++)
		cout<<mmin[i];
	cout<<endl;
	for(i=0;i<m;i++)
		cout<<mmax[i];
	cout<<endl;
	return 0;	
} 
