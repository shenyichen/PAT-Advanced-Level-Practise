#include<iostream>
#include<vector>
using namespace std;
int m,p[31],in[31];
vector<int> level(9999999,-1);
string result;
void pre(int root,int start,int end,int index)
{
	if(start>end) return;
	level[index]=p[root];
	int i=start-1;
	while(i<end && in[i]!=p[root]) i++;
	pre(root-end+i,start,i,2*index+1);
	pre(root-1,i+2,end,2*index+2);
}
int main()
{
	cin>>m;
	for(int i=0;i<m;i++) cin>>p[i];
	for(int i=0;i<m;i++) cin>>in[i];
	pre(m-1,1,m,0); 
	int count=0;
	cout<<level[0];
	for(int i=1;count<m-1;i++)
	{
		if(level[i]!=-1)
		{
			cout<<" "<<level[i];
			count++;
		}
	}
	
}
