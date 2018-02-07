#include<iostream>
#include<set>
#include<vector>

using namespace std;
int k,maxheight=0;
vector<vector<int> > a;
bool visit[10010]={false};
set<int> b,result;
void dfs(int node,int height)
{
	if(height>maxheight)
	{	b.clear();
		b.insert(node);
		maxheight=height;
	}else if(height==maxheight) b.insert(node);
	visit[node]=true;
	for(int i=0;i<a[node].size();i++)
	{
		if(visit[a[node][i]]==false)
		dfs(a[node][i],height+1);
	}
	
	
}

int main()
{
	int n1,n2,cnt=0,tem;
	cin>>k;
	a.resize(k+1);
	for(int i=0;i<k-1;i++)
	{
		cin>>n1>>n2;
		a[n1].push_back(n2);
		a[n2].push_back(n1);	
	} 
	for(int i=1;i<=k;i++)
	{	

			if(visit[i]==false)
			{
				dfs(i,0);
				cnt++;
			}

		

	}
	if(cnt>1) 
	{
			printf("Error: %d components",cnt);
			return 0;
	}

	
	fill(visit,visit+10010,false);
	set<int>::iterator it;
	for(it=b.begin();it!=b.end();it++)
	{
		result.insert(*it);
	}
	tem=*b.begin();		
	dfs(tem,0);
	for(it=b.begin();it!=b.end();it++)
	{
		result.insert(*it);
	}
	for(it=result.begin();it!=result.end();it++)
	cout<<*it<<endl;
	
}
