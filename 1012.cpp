#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct stu{
	int id,C,M,E,A,BR;
	char Best; 
	stu(int id,int C,int M,int E):id(id),C(C),M(M),E(E){
		A=(C+M+E)/3;
	}
	
};

bool ComA(stu S1,stu S2)
{
		return S1.A>S2.A;
	}
	
		bool ComC(stu S1,stu S2)
	{
		return S1.C>S2.C;
	}
		bool ComM(stu S1,stu S2)
	{
		return S1.M>S2.M;
	}
	
		bool ComE(stu S1,stu S2)
	{
		return S1.E>S2.E;
	}

int main(){
	int m,n,id,C,M,E,best;
	vector<stu> v;
	map<int,int>mp; 
//	freopen("E:\\cs2018\\PAT\\testcase\\1012.txt","r",stdin);
	cin>>n>>m;
	if(n==0)
	{
		while(m--) cout<<"N/A"<<endl;
		return 0;
	}
	while(n--)
	{
	 cin>>id>>C>>M>>E;
	 v.push_back(stu(id,C,M,E));	 
	}
	sort(v.begin(),v.end(),ComA);
	int rank=1;
	v[0].BR=1;
	v[0].Best='A';
	for(int i=1;i<v.size();i++)
	{
		if(v[i].A<v[i-1].A) rank=i+1;
		v[i].BR=rank;
		v[i].Best='A';
	 } 

	sort(v.begin(),v.end(),ComC);
	rank=1;
	if(v[0].BR!=1)
	{
	v[0].BR=1;
	v[0].Best='C';
	}
	for(int i=1;i<v.size();i++)
	{
		if(v[i].C<v[i-1].C) rank=i+1;
		best=v[i].BR;
		if(best>rank)
		{
		v[i].BR=rank;
		v[i].Best='C';
			}
	 } 
	 
	sort(v.begin(),v.end(),ComM);
	rank=1;
	if(v[0].BR!=1)
	{
	v[0].BR=1;
	v[0].Best='M';
	}
		for(int i=1;i<v.size();i++)
	{
		if(v[i].M<v[i-1].M) rank=i+1;
		best=v[i].BR;
		if(best>rank)
		{
		v[i].BR=rank;
		v[i].Best='M';
			}
	 } 
	sort(v.begin(),v.end(),ComE);
	
	rank=1;
	if(v[0].BR!=1)
	{
	v[0].BR=1;
	v[0].Best='E';
	}

	for(int i=1;i<v.size();i++)
	{
		if(v[i].E<v[i-1].E) rank=i+1;
		best=v[i].BR;
		if(best>rank)
		{
		v[i].BR=rank;
		v[i].Best='E';
			}
	 } 
	while(m--)
	{
		int q;
		for(int i=0;i<v.size();i++)
		{
			q=v[i].id;
			 mp[q]=i;
		 }
		
		cin>>id;
		if(mp.find(id)==mp.end()) cout<<"N/A"<<endl;
		else 
		{
			q=mp[id];
			cout<<v[q].BR<<" "<<v[q].Best<<endl;
		}
		
	}
}
