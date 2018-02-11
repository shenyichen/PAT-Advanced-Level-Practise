#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;

map<string,vector<string> > adja;
map<string,int> weight,result;
map<string,bool> visit;

int totaltime,gangnumber,maxtime;
string head;
void dfs(string node)
{
	visit[node]=true;
	gangnumber++;
	if(weight[node]>maxtime)
	{
		maxtime=weight[node];
		head=node;
	}
	totaltime+=weight[node];
	for(int i=0;i<adja[node].size();i++)
	{

		string tmp=adja[node][i];
		if(!visit[tmp])
		dfs(tmp);
	}

}

int main()
{
	int a,threhold;
//	freopen("E:\\cs2018\\PAT\\testcase\\1034.txt","r",stdin);
	cin>>a>>threhold; 
	while(a--)
	{
		string a,b;
		int c;
		a.resize(3);
		b.resize(3);
		scanf("%s %s %d",&a[0],&b[0],&c);
		adja[a].push_back(b);
		adja[b].push_back(a);
		visit[a]=false;
		visit[b]=false;
		if(weight.find(a)!=weight.end())
		weight[a]+=c;
		else weight[a]=c;
		if(weight.find(b)!=weight.end())
		weight[b]+=c;
		else weight[b]=c;

	}
	
	map<string,vector<string> >::iterator it;
	
	for(it=adja.begin();it!=adja.end();it++)
	{
		if(!visit[(*it).first])
		{
			maxtime=0;
			gangnumber=0;
			totaltime=0;
			dfs((*it).first);
			if(totaltime/2>threhold && gangnumber>2)
			result[head]=gangnumber; 
		}
	}
	map<string,int>:: iterator it2;
	cout<<result.size();
	for(it2=result.begin();it2!=result.end();it2++){
		
		cout<<endl<<(*it2).first<<" "<<(*it2).second;
	}
	
	
}
