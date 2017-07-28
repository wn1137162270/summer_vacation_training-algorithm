#include<iostream>
#include<cstring>
using namespace std;

const int maxn=50+5;
const int INF=2500+50; 

int getMin(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int i,j,k,n,len,min=INF,count,f[maxn][maxn],flag,ans=0;
	char s[maxn],all[maxn][maxn],t;
	cin>>n;
	cin>>s;
	len=strlen(s);
	for(i=0;i<n;i++)
		for(j=0;j<len;j++)
			f[i][j]=-1;
	for(i=0;i<len;i++)
	{
		if(i==0)
			memcpy(all[i],s,len);
		else
		{
			memcpy(all[i],all[i-1]+1,len-1);
			all[i][len-1]=all[i-1][0];
		}
	}
	for(i=0;i<n;i++)
	{
		if(i)
			cin>>s;
		for(j=0;j<len;j++)
		{
			flag=0;
			for(k=0;k<len;k++)
			{
				if(!memcmp(all[k],s,len))
				{
					if(f[i][k]==-1)
						f[i][k]=j;
					flag=1;
				}
			}
			t=s[0];
			for(k=1;k<len;k++)
				s[k-1]=s[k];
			s[len-1]=t;
			if(flag==0)
				ans=1;
		}
	}
	if(ans)
		cout<<-1<<endl;
	else
	{
		for(i=0;i<len;i++)
		{
			count=0;
			for(j=0;j<n;j++)
				count+=f[j][i];
			min=getMin(min,count);
		}
		cout<<min<<endl;
	}
	return 0;	
} 
