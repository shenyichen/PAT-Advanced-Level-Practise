#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
struct station{
	int dis;
	double fee;
	station(int dis,double fee):dis(dis),fee(fee){
	}
	bool operator <(const station &A)const
	{
		return dis<A.dis;
	}
};
vector<station> stations; 
int max_c,D,Davg,N;
double min_cost,min_fee,now_fee,now_c,now_dis,max_dis;
int main()
{
	cin>>max_c>>D>>Davg>>N;
	while(N--)
	{
		double tem;
		int temd;
		cin>>tem>>temd;
		stations.push_back(station(temd,tem));
	}
	stations.push_back(station(D,0.0));
	sort(stations.begin(),stations.end());
	if(stations[0].dis!=0)
	{
		cout<<"The maximum travel distance = 0.00";
		return 0;
	}
	
	now_dis=0;
	max_dis=max_c*Davg;
	now_fee=stations[0].fee;
	now_c=0;
	min_cost=0;
	while(now_dis<D)
	{
		int flag=-1;
		min_fee=INT_MAX;
		for(int i=1;i<stations.size();i++)
		{
		
		if(stations[i].dis>max_dis) break;
		if(stations[i].dis<=now_dis) continue;
		if(stations[i].fee<now_fee)
		{
			
			min_cost+=((stations[i].dis-now_dis)/Davg-now_c)*now_fee;
			now_fee=stations[i].fee;
			now_dis=stations[i].dis;
			now_c=0;
			flag=-2;
			max_dis=max_c*Davg+now_dis;
			break;
		}else if(stations[i].fee<min_fee)
		{
			min_fee=stations[i].fee;
			flag=i;
		}
		}
		if(flag>-1)
		{
			min_cost+=(max_c-now_c)*now_fee;
			now_c=max_c-(stations[flag].dis-now_dis)/Davg;
			now_fee=stations[flag].fee;
			now_dis=stations[flag].dis;
			max_dis=max_c*Davg+now_dis;			
		}else if(flag==-1)
		{
			printf("The maximum travel distance = %.02f",max_dis);
			return 0;
		}
		 
	}
	
	printf("%.02f",min_cost);
	
}
