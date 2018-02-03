#include<iostream>

using namespace std;
int pre[50001],in[50001],k,ans;

void findpostfirst(int a,int b,int c)
{
	if(a==b-1) ans=in[a];

	for(int i=a;i<b;i++)
	{		
	if(pre[c]==in[i])
	{
		if(i==a)
		{
		findpostfirst(a+1,b,c+1);
		break;	
		}
		findpostfirst(a,i,c+1);
	}
	}	
}

int main()
{
	//freopen("E:\\cs2018\\PAT\\testcase\\1138.txt", "r", stdin);
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>pre[i];
}

	for(int i=0;i<k;i++)
	{
		cin>>in[i];
}
	findpostfirst(0,k,0);
	cout<<ans;
}
