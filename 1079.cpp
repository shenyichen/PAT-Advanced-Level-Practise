#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
vector<vector<bool> > adja;
vector<bool> visit;
map<int,int> retailers;
int level,n;

void dfs(int node)
{
	visit[node]=true;
	level++;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false && adja[node][i])
		dfs(i);
		
	}
}

int main(){
	
	int tmp,tmp2;
	double p,r,total=0;
	cin>>n>>p>>r;
	r/=100;
	r+=1;
	adja.assign(n,vector<bool>(n,false)); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(tmp>0)
		{
			while(tmp--)
			{
				scanf("%d",&tmp2);
				adja[tmp2][i]=true;
			}
		}else{
			scanf("%d",&tmp2);
			retailers[i]=tmp2;
		}
		
		
	}

	for(auto it=retailers.begin();it!=retailers.end();it++)
	{
		level=0;
		visit.assign(n,false);
		dfs(it->first);
		total+=pow(r,level-1)*p*(it->second);
		
	}
	printf("%.1f",total);
} 
