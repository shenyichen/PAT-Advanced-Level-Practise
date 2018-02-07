#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
const int MAX=505;
int min_time=INT_MAX,capacity,s_num,r_num,s_p;
int tem_back,tem_sent;
vector<vector<int> > adjacent(MAX,vector<int>(MAX,-1));
vector<int> stations;
struct pathinfo{
	int send,back;
	vector<int> path;
	pathinfo(int send,int back,vector<int> path):send(send),back(back),path(path){
	}
	bool operator <(const pathinfo &A)const
	{
		if(send==A.send) return back<A.back;
		return send<A.send;
	}
};
vector<pathinfo> result;
void take_bike(vector<int> path)
{
	tem_back=0;
	tem_sent=0;
	for(int i=1;i<path.size();i++)
	{
		if(stations[path[i]-1]<capacity/2)
		{
			if(tem_back<capacity/2-stations[path[i]-1])
			{
				tem_sent+=capacity/2-stations[path[i]-1]-tem_back;
				tem_back=0;
			}else {
				tem_back-=capacity/2-stations[path[i]-1];
			}

			
		}
		
		else tem_back+=stations[path[i]-1]-capacity/2;
	}
}

void dfs(int node,vector<int> path,int current_time)
{
	for(int i=0;i<path.size();i++)
	{
		if(path[i]==node)
		return;
	}
	
	if(node!=0) current_time+=adjacent[path.back()][node];
	
	if(current_time>min_time) return;
	
	path.push_back(node);
	if(node==s_p)
	{
		take_bike(path);
		if(current_time<min_time)
		{	min_time=current_time;
			result.clear();
			result.push_back(pathinfo(tem_sent,tem_back,path));
		}
		if(current_time==min_time)
		result.push_back(pathinfo(tem_sent,tem_back,path));
		return;
	}
	for(int i=1;i<=s_num;i++)
	{
		if(adjacent[node][i]!=-1)
		dfs(i,path,current_time);
	}
	
}

int main()
{
	cin>>capacity>>s_num>>s_p>>r_num;
	for(int i=0;i<s_num;i++)
	{
		int tem;
		cin>>tem;
		stations.push_back(tem);
	}
	
		for(int i=0;i<r_num;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adjacent[a][b]=c;
		adjacent[b][a]=c;
	}
	vector<int> tem;
	dfs(0,tem,0);
	sort(result.begin(),result.end());
	cout<<result[0].send<<" "<<result[0].path[0];
	for(int i=1;i<result[0].path.size();i++)
	{
		cout<<"->"<<result[0].path[i];
	}
	cout<<" "<<result[0].back;
	
}
