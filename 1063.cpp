#include<iostream>
#include<map>
#include<vector> 
using namespace std;
vector<map<int,bool> > query;
int main()
{
	int n,m,tmpn,a,b;
	map<int,bool> tmp;
	cin>>n;
	while(n--)
	{
		tmp.clear();
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&tmpn);
			tmp[tmpn]=true;
		}
		query.push_back(tmp);
	}
	cin>>n;
	double out,cnt;
	while(n--)
	{
		scanf("%d %d",&a,&b);
		a--;
		b--;
		map<int,bool>::iterator it;
		cnt=0;
		for(it=query[a].begin();it!=query[a].end();it++)
		{
			if(query[b].find((*it).first)!=query[b].end())
			cnt++;
		}
		out=cnt/(query[a].size()+query[b].size()-cnt)*100;
		printf("%.01f%%\n",out);
	}
}
