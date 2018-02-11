#include<iostream>
#include<vector>
using namespace std;
struct user{
	string name,pass;
	user(string name,string pass):name(name),pass(pass){
	}
}; 
vector<user> result;

int main()
{
	int sum;
	cin>>sum;

	for(int i=0;i<sum;i++)
	{
		string a,b,c;
		cin>>a>>b;
		c=b;
		for(int j=0;j<b.size();j++)
		{
			if(b[j]=='1')
			b[j]='@';
			if(b[j]=='0')
			b[j]='%';
			if(b[j]=='l')
			b[j]='L';
			if(b[j]=='O')
			b[j]='o';
		}
		if(c!=b) result.push_back(user(a,b));
		
	}
	
	if(result.size()!=0)
	{
		cout<<result.size()<<endl;
		for(int i=0;i<result.size();i++)
		cout<<result[i].name<<" "<<result[i].pass<<endl;
	}
	else if (sum==1) printf("There is %d account and no account is modified",sum);
	else printf("There are %d accounts and no account is modified",sum);
}
