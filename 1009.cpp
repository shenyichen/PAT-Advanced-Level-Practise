#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
float ployA[1001]={0};
float ployB[1001]={0};
map<int,float> result;
int k,exp;
float coe;
int main(){
	cin>>k;
	while(k--)
	{
		cin>>exp;
		cin>>coe;
		ployA[exp]=coe;
	}
	cin>>k;
	while(k--)
	{
		cin>>exp;
		cin>>coe;
		ployB[exp]=coe;
	}
	
	for(int i=1000;i>=0;i--)
	{
			for(int j=1000;j>=0;j--)
	{
		if(ployA[i]!=0 && ployB[j]!=0)
		{
			result[i+j]+=ployA[i]*ployB[j];
			if(result[i+j]==0)(result.erase(i+j));
		}
		
	}
	
	
	
	}
	cout<<result.size();
	map<int,float>::reverse_iterator it;
	for(it=result.rbegin();it!=result.rend();it++)
	{
		cout<<" ";
		cout<<it->first;
		printf(" %.1f",it->second);
	}
} 
