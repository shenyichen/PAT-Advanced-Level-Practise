#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> order(2001,-1),stripe,result(2001,0); 



int main()
{
	int n,t,tmp;
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		order[tmp]=i;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tmp);
		stripe.push_back(order[tmp]);
	}
	int max,len=0;
	for(int i=0;i<stripe.size();i++)
	{
		if(stripe[i]==-1) continue;
		max=0;
		for(int j=0;j<stripe[i]+1;j++)
		{
			if(max<result[j])max=result[j];
		}
		result[stripe[i]]=max+1;
		if(max+1>len) len=max+1;
	 } 
		
	 cout<<len;
}
