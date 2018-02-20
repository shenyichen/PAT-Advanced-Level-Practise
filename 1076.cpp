#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<bool> > dja(1010,vector<bool>(1010,false));
vector<bool> visit(1010,false);
int n,l,s,tmp,sum;

void bfs(int node)
{
	queue<int> next;
	vector<int> cnt(7,0);
	cnt[0]=1;
	int level=0;
	next.push(node);
	visit[node]=true;
	while(!next.empty() && level<l)
	{
		node=next.front();
		next.pop();
		cnt[level]--;	
		for(int i=1;i<=n;i++)
		{
			if(!visit[i] && dja[node][i])
			{
				next.push(i);
				cnt[level+1]++;
				visit[i]=true;
				sum++;
			
			}
		
		}
	
		


		
		if(cnt[level]==0)
		level++;
		
	}
	 
	
}

int main()
{
	
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s);
		while(s--)
		{
			scanf("%d",&tmp);
			if(tmp!=i)
			dja[tmp][i]=true;
		}
	}
	
	cin>>s;
	while(s--)
	{
		scanf("%d",&tmp);
		sum=0;
		visit.assign(1010,false);
		bfs(tmp);
		cout<<sum<<endl;
	}
}
