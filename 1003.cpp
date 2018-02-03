#include <cstdio>
#include <climits>
const int MAX=501;

int visit[MAX],rescue[MAX],map[MAX][MAX];
int mindis,cdis,maxres,n;
void init(int n)
{
	mindis=INT_MAX;
	for(int i=0;i<n;i++)
	{
	
	visit[i]=0;
	for(int j=0;j<n;j++)
	{
		map[i][j]=INT_MAX;
	}
     }
}

void dfs(int c,const int d,int dis,int res)
{
	if(c==d)
	{
		if(dis<mindis)
		{
			mindis=dis;
			cdis=1;
			maxres=res;
		}
		else if(dis==mindis)
		{
			cdis++;
			if(maxres<res) maxres=res;
		}
		
		return;
		
	}
	if(dis>mindis) return;
	for(int i=0;i<n;i++)
	{
		
		if(visit[i]==0 && map[c][i]!=INT_MAX)
		{
		visit[i]=1;
		dfs(i,d,dis+map[c][i],res+rescue[i]);
		visit[i]=0;
     	}
	}
	
}

int main()
{
	int m,c,d,a,b,w;
	scanf("%d %d %d %d",&n,&m,&c,&d);
	init(n);
	for(int i=0;i<n;i++) scanf("%d",&rescue[i]);  
	while(m--)
	{
		scanf("%d %d %d",&a,&b,&w);
		if(w<map[a][b]) map[a][b]=map[b][a]=w;
	}
	dfs(c,d,0,rescue[c]);
	printf("%d %d",cdis,maxres);
}


