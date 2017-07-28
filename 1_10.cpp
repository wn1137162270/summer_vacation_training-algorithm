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
	int i,j,n,len,state[maxn],count,min=INF,v,flag;
	char s[maxn],all[maxn][maxn],t;
	cin>>n;
	cin>>s;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(i==0)
			memcpy(all[i],s,len);
		else
		{
			t=all[i-1][0];
			memcpy(all[i],all[i-1]+1,len-1);
			all[i][len-1]=t;
		}
	}
	state[0]=0;
	for(i=1;i<n;i++)
	{
		cin>>s;
		flag=0;
		for(j=0;j<len;j++)
		{
			if(!memcmp(all[j],s,len))
			{
				state[i]=j;
				flag=1;
				break;
			}
		}
		if(flag==0)
			break;
	}
	if(!flag)
		cout<<-1<<endl;
	else
	{
		for(i=0;i<len;i++)
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(state[j]<=i)
					count+=i-state[j];
				else
					count+=len+i-state[j];
			}
			min=getMin(min,count);
		}
		cout<<min<<endl;
	}
	return 0;
}
