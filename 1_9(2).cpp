#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int maxn=100000+5;
int num=0,loc[26];

void firstFind()
{
	while(loc[num]==-1)
	{
		num++;
	}
}

void find(int cur)
{
	num++;
	while(loc[num]==-1||loc[num]<loc[cur])
	{
		num++;
	}
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
			loc[s[i]-'a']=i;
	}
	firstFind();
	for(i=0;i<len;i++)
	{
		st.push(s[i]);
		if(s[i]==num+'a')
		{
			ans[k]=st.top();
			st.pop();
			k++;
		}
		if(i==loc[num])
		{
			if(i==len-1)
				break;
			find(num);
			while(!st.empty()&&st.top()<=num+'a')
			{
				ans[k]=st.top();
				st.pop();
				k++;
			}
		}
	}
	while(!st.empty())   
	{
		ans[k]=st.top();
		st.pop();
		k++;
	}
	ans[k]='\0'; 
	cout<<ans<<endl;
	return 0;
}
//对于char类型的数组当用作字符串输出时，最后必须要加'\0'，否则后面会输出不必要的内容，或者单个字符输出 
