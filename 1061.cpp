#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
string wk[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
map<int,char> index1;
vector<char> result1;
int main()
{
	string str1,str2,str3,str4;
	cin>>str1>>str2>>str3>>str4;
	char tmp;
	for(int i=str1.size()-1;i>=0;i--)
	{
		tmp=str1[i];
		if(tmp>='0' && tmp<='9')
		index1[i]=tmp;
		else if(tmp>='A' && tmp<='N') index1[i]=tmp;	
	}
	map<int,char>::iterator it;
	for(it=index1.begin();it!=index1.end();it++)
	{
		
		if(str2[(*it).first]==(*it).second)
		result1.push_back((*it).second);
		
	}
	int minsize=min(str3.size(),str4.size());
	int p=0,first,last;
	for(int i=0;i<minsize;i++)
	{
		if((str3[i]>='a' && str3[i]<='z' )|| (str3[i]>='A' && str3[i]<='Z' ))
		{
			
			if(str3[i]==str4[i])
			{
				p=i;
				break;
			}
			
		}
	}
	for(int i=0;i<result1.size();i++)
	{
		if(result1[i]<'A')
		continue;
		else {
			first=result1[i]-'A';
			if(result1[i+1]<'A')
			last=result1[i+1]-'0';
			else last=result1[i+1]-'A'+10;
			break;
			
		}
	}
	printf("%s %02d:%02d",wk[first].c_str(),last,p);
	

}
