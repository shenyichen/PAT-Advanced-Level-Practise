#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> in,out;
void cbt(int begin,int end,int index)
{
	int p=1,size=end-begin+1,i=0,now,root;
	while(p<size)
	{
		i++;
		p=pow(2,i)-1;
		
	}
	if(p>size)
	{
		p=p-size;
		now=pow(2,i-1);		
		if(p>now/2)
		p=now-p;							
	}else p=0;
	root=(begin+p+end)/2;
	out[index]=in[root];
	int nextindex=index*2+1;
	if(nextindex<out.size())
	cbt(begin,root-1,nextindex);
	nextindex=index*2+2;
	if(nextindex<out.size())
	cbt(root+1,end,nextindex);
	return;
}
int main()
{
	int n,tmp;
	cin>>n;
	while(n--)
	{
		scanf("%d",&tmp);
		in.push_back(tmp);
	}
	sort(in.begin(),in.end());
	out.resize(in.size());
	cbt(0,in.size()-1,0);
	for(int i=0;i<out.size();i++)
	{
	if(i==0)printf("%d",out[i]);
	else printf(" %d",out[i]);
	}

}
