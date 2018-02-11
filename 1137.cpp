#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

struct student{
	string name;
	int o,m,f,g;
	student(string name="",int o=-1,int m=-1,int f=-1,int g=-1):name(name),o(o),m(m),f(f),g(g){
	}
	bool operator < (const student &a)const{
		if(g==a.g)
		{
		return name>a.name;
		}else return g<a.g;
	}
};

int main(){
	int a,b,c,o;
	string n;
	//freopen("E:\\cs2018\\PAT\\testcase\\1137.txt","r",stdin);
	cin>>a>>b>>c;
	vector<student> v;
	map<string,student> mp;
	while(a--)
	{
		cin>>n;
		cin>>o;
		if(o>=200) mp[n]=student(n,o,-1,-1,-1);

	}

	while(b--)
	{
		cin>>n;
		cin>>o;
		if(mp.count(n)>0) mp[n].m=o;
	}

	while(c--)
	{
		cin>>n;
		cin>>o;
		if(mp.count(n)>0)
		{
			int m=mp[n].m;
			mp[n].f=o;
			
			if(m>o)mp[n].g=m*0.4+o*0.6+0.5;
			else mp[n].g=o;
			if(mp[n].g>=60)v.push_back(mp[n]);
			
		}
		

	}
	sort(v.begin(),v.end());
	

	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i].name<<" "<<v[i].o<<" "<<v[i].m<<" "<<v[i].f<<" "<<v[i].g<<endl;
	}
	
}
