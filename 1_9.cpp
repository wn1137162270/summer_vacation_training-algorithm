#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
//dresdcf

const int maxn=100000+5;
int num=0,loc[26],v;

int firstFind()
{
	if(num==v)
		return -1;
	while(loc[num]==-1)
	{
		num++;
		if(num==v)
			return -1;
	}
	return 0;
}

int find(int cur)
{
	num++;
	if(num==v)
		return -1;
	while(loc[num]==-1||loc[num]<loc[cur])
	{
		num++;
		if(num==v)
			return -1;
	}
	return 0;
}

int main()
{
	stack<char> st;
	int i,len,k=0,ret;
	char s[maxn],ans[maxn];
	cin>>s;
	len=strlen(s);
	for(i=0;i<26;i++)
		loc[i]=-1;
	for(i=len-1;i>=0;i--)
	{
		if(loc[s[i]-'a']==-1)
		{
			loc[s[i]-'a']=i;
			//cout<<loc[i]<<endl; 
		}
	}
	for(i=25;i>=0;i--)
	{
		if(loc[i]!=-1)
		{
			v=i;
			break;
		}
	}
	//<<"v:"<<v<<endl;
//	for(i=0;i<4;i++)
//		cout<<i<<' '<<loc[i]<<endl; 
	ret=firstFind();
	if(ret==-1)
	{
		cout<<s<<endl;
		return 0;
	}
	//cout<<"num:"<<num<<endl;
	for(i=0;i<len;i++)
	{
		if(i<=loc[num])
		{
			st.push(s[i]);
			//cout<<"push:"<<s[i]<<endl;
			if(s[i]==num+'a')
			{
				ans[k]=st.top();
				st.pop();
				//cout<<"pop1:"<<ans[k]<<endl;
				k++;
			}
			if(i==loc[num])
			{
				ret=find(num);
				if(ret==-1)
					break;
				while(!st.empty()&&st.top()<=num+'a')
				{
					ans[k]=st.top();
					st.pop();
					//cout<<"pop2:"<<ans[k]<<endl;
					k++;
				}
			}
		}
	}
	while(!st.empty())
	{
		ans[k]=st.top();
		st.pop();
		//cout<<"pop3:"<<ans[k]<<endl;
		k++;
	}
	i++;
	for(;i<len;i++)
	{
		ans[k]=s[i];
		k++;
	}
	cout<<ans<<endl;
	return 0;
}
