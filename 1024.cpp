#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
string k,t;
stack<int> temk;
queue<int> temq;
int main()
{
	int a;
	cin>>k>>a;
	t=k;
	reverse(t.begin(),t.end());
	if(t==k)
	{
		cout<<k<<endl<<"0";
		return 0;
	}
		for(int j=1;j<=a;j++)
		{
		

		bool flag=false;
		int s=k.size()-1;
		for(int i=s;i>=0;i--)
		{
				int tem=k[s-i]+k[i]-2*'0';
				if(flag) tem++;
				flag=false;
				if(tem>=10)
				{
					flag=true;
					tem-=10;
				}
				temk.push(tem);
				temq.push(tem);			
		}
		bool fl=true;
		k="";
		if(flag)	
		{
		temk.push(1);
		}
			

		while(!temk.empty())
		{	k+=temk.top()+'0';
			if(temk.top()!=temq.front()) fl=false; 
			temk.pop();
			temq.pop();
			if(temk.size()==1 &&flag)
			{
			k+=temk.top()+'0';
			if(temk.top()!=1) fl=false;
			temk.pop();
			}

		}
		
		if(fl)
		{
			cout<<k<<endl;
			cout<<j;
			return 0;
		}else if(j==a)
		{
			cout<<k<<endl;
			cout<<j;
			return 0;
		}
		
		}
		



 } 
