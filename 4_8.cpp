#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=200000+10;

struct node
{
	int price,index;	
	bool operator < (const node& nd) const
	{
		return price>nd.price;
	}
};

int main()
{
	int i,j,n,m,p[maxn],num,vis[maxn],fv,len[3],flag;
	vector<node> color[3]; 
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i];
	for(j=0;j<2;j++)
		for(i=0;i<n;i++)
		{
			cin>>num;
			color[num-1].push_back((node){p[i],i});
		}
	memset(vis,0,sizeof(vis));
	for(i=0;i<3;i++)
	{
		len[i]=color[i].size();
		sort(color[i].begin(),color[i].end());
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>fv;
		while(len[fv-1]&&vis[color[fv-1][len[fv-1]-1].index])
		{
			len[fv-1]--;
		}
		if(len[fv-1]==0)
		{
			if(i==m-1)
				cout<<-1;
			else
				cout<<-1<<' ';
		}
		else
		{
			vis[color[fv-1][len[fv-1]-1].index]=1;
			if(i==m-1)
				cout<<color[fv-1][len[fv-1]-1].price;
			else
				cout<<color[fv-1][len[fv-1]-1].price<<' ';
			len[fv-1]--;
		}
	}
	cout<<endl;
	return 0;	
} 
