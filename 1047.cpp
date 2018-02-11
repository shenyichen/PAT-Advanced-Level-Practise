#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > index;
vector<string> name,tmpv;
int main()
{
	int n,k,m,l,q;
	string tmp;
	scanf("%d%d",&n,&k);
	index.resize(k);
	while(n--)
	{
		tmp.resize(4);
		scanf("%s %d",&tmp[0],&m);
		name.push_back(tmp);
		q=name.size()-1;
		
		while(m--)
		{
		scanf("%d",&l);
		index[l-1].push_back(q);
		}
		
	}
	for(int j=0;j<k;j++)
	{
		printf("%d %d\n",j+1,index[j].size());

		tmpv.clear();
		for(int i=0;i<index[j].size();i++)
		{
			tmpv.push_back(name[index[j][i]]);
			
		}
		sort(tmpv.begin(),tmpv.end());
			for(int i=0;i<index[j].size();i++)
		{
				printf("%s\n",tmpv[i].c_str());
		}
 
	}
		
	
 } 
