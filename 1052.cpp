#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	int addr,num;
	node(int addr,int num):addr(addr),num(num){
	}
	bool operator <(const node &A)const
	{
		return num<A.num; 
	}
};

map<int,bool> exsit;
vector<node> list;

int main(){
	
	int n,m,tmp,addr,addr2,flag=false;
	cin>>n>>m;
	exsit[m]=true;
	while(n--)
	{
		scanf("%d%d%d",&addr,&tmp,&addr2);
		if(addr==m)
		flag=true;
		exsit[addr2]=true;
		list.push_back(node(addr,tmp));
	}
	if(!flag)
	{
		printf("0 -1\n");
		return 0;
	}
		for(int i=0;i<list.size();i++)
	{
		if(exsit.find(list[i].addr)==exsit.end())
		list.erase(list.begin()+i);
	}
	sort(list.begin(),list.end());
	if(list.size()>0)
	{
		printf("%d %05d\n",list.size(),list[0].addr);
	for(int i=0;i<list.size()-1;i++)
	{
	printf("%05d %d %05d\n",list[i].addr,list[i].num,list[i+1].addr);
	}	
	printf("%05d %d %d\n",list[list.size()-1].addr,list[list.size()-1].num,-1);	
	}else printf("0 -1\n");

}
