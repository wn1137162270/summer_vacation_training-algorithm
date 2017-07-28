#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int maxn=1000+10;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

int n,m,sx,sy,ex,ey;
char maze[maxn][maxn];
bool visit[maxn][maxn];

struct node
{
	int x,y,turn;	
};

bool judge(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&maze[x][y]!='*')
		return true;
	return false;
}

int bfs()
{
	int i;
	queue<node> qu;
	node nd,temp;
	nd.x=sx;
	nd.y=sy;
	nd.turn=-1;
	qu.push(nd);
	visit[sx][sy]=true;
	while(!qu.empty())
	{
		nd=qu.front();
		qu.pop();
		printf("pop:%d %d\n",nd.x,nd.y);
		temp.turn=nd.turn+1;
		if(temp.turn==3)
			return 0;
		for(i=0;i<4;i++)
		{
			temp.x=nd.x+dx[i];
			temp.y=nd.y+dy[i];
			while(judge(temp.x,temp.y))
			{
				if(temp.x==ex&&temp.y==ey)
					return 1;
				if(!visit[temp.x][temp.y])
				{
					qu.push(nd);
					printf("push:%d %d\n",temp.x,temp.y);
					visit[temp.x][temp.y]=true;
				}
				temp.x=temp.x+dx[i];
				temp.y=temp.y+dy[i];	
			}
		}
	}
}

int main()
{
	int i,j,ans;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",maze[i]);
	memset(visit,false,sizeof(visit));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(maze[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			if(maze[i][j]=='T')
			{
				ex=i;
				ey=j;
			}
		}
	}
	ans=bfs();
	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
