#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=1000+10;
const int maxm=20+5;

int main()
{
	int i,j,k,h,n,flag=0,f[26];
	char team[maxm],home[maxm],l[maxn],r[maxn],ans[maxn],t,st[maxn][2];
	vector<int> index[26][26];
	vector<int> find[26];
	queue<char> qu;  
	ios::sync_with_stdio(false);
	cin>>n;
	memset(ans,0,sizeof(ans));
	for(i=0;i<n;i++)
	{
		cin>>team>>home;
		st[i][0]=team[0];
		st[i][1]=team[1];
		l[i]=team[2];
		r[i]=home[0];
		index[team[0]-'A'][team[1]-'A'].push_back(i);
	}
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			if(index[i][j].size()>26)
			{
				flag=1;
				break;
			}
			if(index[i][j].size()>1)
			{
				//cout<<"i:"<<i<<"   j:"<<j<<endl;
				memset(f,0,sizeof(f));
				for(vector<int>::iterator it=index[i][j].begin();it!=index[i][j].end();it++)
				{
					find[l[*it]-'A'].push_back(*it);
				}
				for(k=0;k<26;k++)
				{
					if(find[k].size()>1)
					{
						for(vector<int>::iterator it=find[k].begin();it!=find[k].end();it++)
						{
							ans[*it]=r[*it];
							qu.push(r[*it]);
							//cout<<"push:"<<r[find[k][h]]<<endl;
							if(f[r[*it]-'A']==0)
								f[r[*it]-'A']=1;
							else
							{
								flag=1;
								break;
							}
						}	
						if(flag==1)
							break;			
					}
				}
				if(flag==1)
					break;
				while(!qu.empty())
				{
					t=qu.front();
					qu.pop();
					//cout<<"pop:"<<t<<endl;
					if(find[t-'A'].size()==1)
					{
						ans[find[t-'A'][0]]=r[find[t-'A'][0]];
						if(f[r[find[t-'A'][0]]-'A']==0)
							f[r[find[t-'A'][0]]-'A']=1;
						else
						{
							flag=1;
							break;
						}
						qu.push(r[find[t-'A'][0]]);
						//cout<<"push:"<<r[find[t-'A'][0]]<<endl;
					}
				}
				if(flag==1)
					break;
				for(k=0;k<26;k++)
				{
					find[k].clear();
				}
			}
		}
		if(flag==1)
			break;
	}
	if(flag==1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for(i=0;i<n;i++)
			if(ans[i]==0)
				cout<<st[i][0]<<st[i][1]<<l[i]<<endl;
			else
				cout<<st[i][0]<<st[i][1]<<ans[i]<<endl;
	}
	return 0;
}
