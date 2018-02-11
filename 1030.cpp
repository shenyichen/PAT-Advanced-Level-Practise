#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int min_cost=INT_MAX,min_dis=INT_MAX,D,N;
vector<int> bestnode;
vector<vector<int> > adjad(501,vector<int>(501,-1));
vector<vector<int> > adjac(501,vector<int>(501,-1));
void dfs(int node,vector<int> path,int cost,int dis)
{
	for(int i=0;i<path.size();i++)
	if(path[i]==node) return;
	if(dis>min_dis) return;
	path.push_back(node); 
	if(D==node)
	{
			if(dis==min_dis)
			{
				
			if(min_cost>cost)
			{
				min_cost=cost;
				bestnode=path;
			}
				
			}else
			{
				min_dis=dis;
				min_cost=cost;
				bestnode=path;
			}
			
		
				return;

		
	}
		

	
	for(int i=0;i<N;i++)
	{
		if(adjad[node][i]!=-1)
		dfs(i,path,cost+adjac[node][i],dis+adjad[node][i]);
	}
}
int main()
{
	int M,S;
	cin>>N>>M>>S>>D;
	while(M--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		adjad[a][b]=c;
		adjad[b][a]=c;
		adjac[a][b]=d;
		adjac[b][a]=d;
	}
	
	dfs(S,bestnode,0,0);
	for(int i=0;i<bestnode.size();i++)
	{
		cout<<bestnode[i]<<" ";
	}
	cout<<min_dis<<" "<<min_cost;
}
