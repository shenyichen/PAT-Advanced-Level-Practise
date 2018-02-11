#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,postb,postm;

void isBin(int start,int end)
{
	if(end<start) return;
	if(end==start) 
	{
		postb.push_back(pre[start]);
		return;	
	}
	int right=end+1;
	for(int i=start+1;i<=end;i++)
	if(pre[i]>=pre[start])
	{
		right=i;
		break;
	}
	for(int i=start+1;i<right;i++)
	{
		if(pre[i]>=pre[start]) return;
	}
	isBin(start+1,right-1);
		for(int i=right;i<=end;i++)
	{
		if(pre[i]<pre[start]) return;
	}
	isBin(right,end);
	postb.push_back(pre[start]);	

}

void isBinM(int start,int end)
{
	if(end<start) return;
	if(end==start) 
	{
		postm.push_back(pre[start]);
		return;	
	}
	
	int right=end+1;
	for(int i=start+1;i<=end;i++)
	if(pre[i]<pre[start])
	{
		right=i;
		break;
	}
	

	for(int i=start+1;i<right;i++)
	{
		if(pre[i]<pre[start]) return;
	}
	isBinM(start+1,right-1);
	for(int i=right;i<=end;i++)
	{
		if(pre[i]>=pre[start]) return;
	}
	isBinM(right,end);
	postm.push_back(pre[start]);	

}


int main()
{
	int a,b;
	cin>>a;
	while(a--)
	{
		cin>>b;
		pre.push_back(b);
	}
	isBin(0,pre.size()-1);
	isBinM(0,pre.size()-1);

	if(postb.size()==pre.size())
	{
	cout<<"YES"<<endl<<postb[0];
	for(int i=1;i<postb.size();i++)
	cout<<" "<<postb[i];
	return 0;
	}
		if(postm.size()==pre.size())
	{
	cout<<"YES"<<endl<<postm[0];
	for(int i=1;i<postm.size();i++)
	cout<<" "<<postm[i];
	return 0;
	}
	cout<<"NO";
	

 } 
