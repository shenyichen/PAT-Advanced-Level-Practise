#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct grade{
	string id;
	int score,location,localrank,finalrank;
	grade(string id,int score,int location):id(id),score(score),location(location){
	}
	bool operator < (const grade &A)const{
		if(score==A.score)
		{
			return id<A.id;
		}else return score>A.score;
		
	}
};
vector<grade> temp,total;
int sum;
int main(){
	int n,testees=0;
//	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1125.txt","r",stdin);
	cin>>sum;
	for(int i=1;i<=sum;i++)
	{
		
		cin>>n;
		testees+=n;
		while(n--)
		{
			string id;
			int score;
			cin>>id>>score;
			temp.push_back(grade(id,score,i));
		}
		sort(temp.begin(),temp.end());
		int rank=1;
		temp[0].localrank=rank;
		total.push_back(temp[0]);
		for(int j=1;j<temp.size();j++)
		{
			if(temp[j].score<temp[j-1].score) rank=j+1;
			temp[j].localrank=rank;
			total.push_back(temp[j]);
		}
		temp.clear();
		
	}
	sort(total.begin(),total.end());
	int rank=1;
	total[0].finalrank=rank;
	for(int j=1;j<total.size();j++)
	{
		if(total[j].score<total[j-1].score) rank=j+1;
		total[j].finalrank=rank;
	}
	
	cout<<testees<<endl;
	for(int i=0;i<total.size();i++)
	{
		cout<<total[i].id<<" "<<total[i].finalrank<<" "<<total[i].location<<" "<<total[i].localrank<<endl;
	}
}
