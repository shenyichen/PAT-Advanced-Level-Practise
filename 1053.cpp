#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> weight,temcw;
vector<bool> nonleaf;
vector<vector<int> > node,wlist;
int n,m,w,tmp,id,k;
void dfs(int cnode,int cweight,vector<int> cwlist)
{
	cweight+=weight[cnode];
	if(cweight>w) return;
	cwlist.push_back(weight[cnode]);

	if(!nonleaf[cnode]) 
	{
	if(cweight==w) 
	{
		wlist.push_back(cwlist);
		return;
	}else return;
	}

	for(int i=0;i<node[cnode].size();i++)
	{
		dfs(node[cnode][i],cweight,cwlist);	
	} 


}
bool cmp(const vector<int> &A,const vector<int> &B)
{
	int minu=min(A.size(),B.size());
	for(int i=0;i<minu;i++)
	{
		if(A[i]>B[i]) return true;
		else if(A[i]<B[i]) return false;
	}
	return false;
}
int main()
{
	
	cin>>n>>m>>w;
	node.resize(n);
	nonleaf.assign(n,false);
	while(n--)
	{
		scanf("%d",&tmp);
		weight.push_back(tmp);
	}
	while(m--)
	{
		scanf("%d %d",&id,&k);
		nonleaf[id]=true;
		while(k--)
		{
			scanf("%d",&tmp);
			node[id].push_back(tmp);
			
		}
	}
	
	dfs(0,0,temcw);
	sort(wlist.begin(),wlist.end(),cmp);
	for(int i=0;i<wlist.size();i++)
	{
		for(int j=0;j<wlist[i].size();j++)
		{
			if(j==0) cout<<wlist[i][j];
			else if(j==wlist[i].size()-1)
			cout<<" "<<wlist[i][j]<<endl;
			else cout<<" "<<wlist[i][j];
		}

	}
	
}
