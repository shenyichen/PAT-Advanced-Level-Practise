#include<iostream>
#include<vector>
using namespace std;
vector<bool> index(256,false);
using namespace std;
int main(){
	string in,sub,out;
	getline(cin,in);
	getline(cin,sub);
	for(int i=0;i<sub.size();i++)
	{
		index[sub[i]]=true;
	}
	for(int i=0;i<in.size();i++)
	{
		if(!index[in[i]])
		out+=in[i];
	}
	cout<<out;
}
