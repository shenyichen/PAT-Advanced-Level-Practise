#include<iostream>
#include<vector>
using namespace std;
vector<int> weight,winorder,nexrgroup,nextt;
int main()
{
	int p,g,tmp;
	cin>>p>>g;
	winorder.assign(p,-1);
	for(int i=0;i<p;i++)
	{
		scanf("%d",&tmp);
		weight.push_back(tmp);
	}

		for(int i=0;i<p;i++)
	{
		scanf("%d",&tmp);
		nexrgroup.push_back(tmp);
	}
		int max,maxnum,order=0,left=nexrgroup.size(),gnum;
		max=0;
		maxnum=0;
	while(left>1)
	{
		
		gnum=left/g;
		if(left%g!=0)
		gnum++;
		for(int i=0;i<gnum;i++)
	{	max=0;
		maxnum=0;

		for(int j=i*g;j<(i+1)*g && j<left;j++)
		{
			if(weight[nexrgroup[j]]>max)
			{
				maxnum=nexrgroup[j];
				max=weight[nexrgroup[j]];
			}
		}
		for(int j=i*g;j<(i+1)*g && j<left;j++)
		{
			if(maxnum!=nexrgroup[j] && max!=-1)
			{
				winorder[nexrgroup[j]]=gnum+1;
				
			}else{

					

				nextt.push_back(maxnum);
			}
			
		}
	}		nexrgroup.assign(nextt.begin(),nextt.end());
			nextt.clear();
			left=nexrgroup.size();
	}
	winorder[maxnum]=1;
	for(int i=0;i<winorder.size();i++)
	{
		if(i==winorder.size()-1) cout<<winorder[winorder.size()-1];
		else cout<<winorder[i]<<" ";
	}

 } 
