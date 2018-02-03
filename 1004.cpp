#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int,vector<int> > list;
int leaves[105]={0};

void dfs(int node,int order)
{
	if(list[node].empty()){
	leaves[order]++;
	return; 
	} 
	vector<int>:: iterator it =list[node].begin();
	for(;it<list[node].end();it++)
	{
		dfs(*it,order+1);
	}
}


int main(){
	int n,m;
	int leaf;
	cin>>n;
	cin>>m;
	leaf=n-m;
	for(int i=0;i<m;i++)
	{
		int k,id1,id2;
		cin>>id1;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>id2;
			list[id1].push_back(id2);
		}
	 }
	 dfs(1,0);
	 cout<< leaves[0];
	 int a=leaves[0];
	 for(int q=1;a<leaf;q++)
	 {
	 	cout<<" "<<leaves[q];
	 	a+=leaves[q];
	 }
}
