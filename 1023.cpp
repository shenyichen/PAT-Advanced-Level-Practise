#include<iostream>
#include<map>
#include<stack>
using namespace std;
string N;
stack<int> M;
map<int,int> count1,count2;
int main()
{
	cin>>N;
	map<int,int>:: iterator it;
	for(int i=0;i<N.size();i++)
	{
		int tem=N[i]-'0';
		if(count1.find(tem)==count1.end()) count1[tem]=1;
		else count1[tem]++;
	}

	bool f=false;
	
	for(int i=N.size()-1;i>=0;i--)
	{
		int tem=(N[i]-'0')*2;
		if(f==true)
		{
			tem++;
			f=false;
		}

		if(tem>=10)
		{
			f=true;
			tem-=10;
		}
		M.push(tem);
		if(count2.find(tem)==count2.end()) count2[tem]=1;
		else count2[tem]++;
		
	}
	if(f==true)
	{
		M.push(1);
		if(count2.find(1)==count2.end()) count2[1]=1;
		else count2[1]++;
	}

	bool flag=false;
	for(it=count2.begin();it!=count2.end();it++)
	{
		if(count1.find((*it).first)!=count1.end())
		{
			if(count1[(*it).first]==(*it).second) flag=true;
			else 
			{	flag=false;
				break;
			}
			
		}else 
			{	flag=false;
				break;
			}
	}
	if(flag==true) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	while(!M.empty())
	{
		cout<<M.top();
		M.pop();
	}
	
	
}
