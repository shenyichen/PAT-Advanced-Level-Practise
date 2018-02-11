#include<iostream>
#include<vector>
using namespace std;
vector<int> list(100002,-1);
vector<int> visit(100002,-1);
int main()
{
	int add1,add2,n;
	int a,b;
	cin>>add1>>add2>>n;
	for(int i=0;i<n;i++)
	{
		
		char c[10];
		scanf("%d %s %d",&a,c,&b);
		list[a]=b;
	}
	int a1=list[add1];
	visit[add1]=1;
	while(a1!=-1)
	{
		visit[a1]=1;
		a1=list[a1];
	}
	if(visit[add2]==1)
	{
		printf("%05d",add2);
		return 0;
	}
	int a2=list[add2];
	while(a2!=-1)
	{
		if(visit[a2]!=1)
		a2=list[a2];
		else break;
	}
	if(a2==-1)
	printf("%d",a2);
	else printf("%05d",a2);
	
}
