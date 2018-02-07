#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
struct record{
	string name,time,of;
	int minute,day,hour;
	record(string name,string time,string of):name(name),time(time),of(of){
		minute=0;
		day=(time[3]-'0')*10;
		day+=time[4]-'0';
		hour=(time[6]-'0')*10;
		hour+=time[7]-'0';
		minute=(time[9]-'0')*10;
		minute+=time[10]-'0';
	};
	bool operator < (const record &B)const{
		if(name<B.name) return 1;
		if(name>B.name) return 0;
		if(time<B.time) return 1;
		if(time>=B.time) return 0;	

	}
};


vector<record> re;
map<string,vector<record> > custom;
int cost[24],sum;
double rate[1500];

double countbill(record A,record B)
{	double result;
	int Aminute=A.hour*60+A.minute;
	int Bminute=B.hour*60+B.minute;
	int totaltime=(B.day-A.day)*24*60;
	totaltime+=Bminute-Aminute;
	cout<<totaltime<<" ";
	if(Bminute<Aminute)
	{
		result=(B.day-A.day+1)*rate[1440];
		result-=rate[1440]-rate[Bminute];
		result-=rate[Aminute];
	}else result=(totaltime/1440)*rate[1440]+rate[Bminute]-rate[Aminute];
	
	result/=100; 
	return result;
}

int main()
{
//	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1016.txt","r",stdin);
	string name,time,of;
	for(int i=0;i<24;i++) cin>>cost[i];
	rate[0]=0;
	for(int i=1;i<=1440;i++)
	{
		int q=(i-1)/60;
		rate[i]=rate[i-1]+cost[q];
	}
	rate[1440]=rate[1439]+cost[23];
	cin>>sum;
	for(int i=0;i<sum;i++)
	{
		cin>>name>>time>>of;
		re.push_back(record(name,time,of));
	}
	
	sort(re.begin(),re.end());
	for(int i=0;i<sum-1;i++)
	{
		if(re[i].of=="on-line" && re[i+1].of=="off-line" && re[i+1].name==re[i].name)
		{
			custom[re[i].name].push_back(re[i]);
			custom[re[i].name].push_back(re[i+1]);
		}
	}
	
	for(auto it : custom)
	{
		vector<record> temp= it.second;
		cout<<it.first<<" "<<temp[0].time.substr(0,2)<<endl;
		double total=0;
		for(int i=0;i<temp.size();i+=2)
		{	
			
			cout<<temp[i].time.substr(3,9)<<" ";
			cout<<temp[i+1].time.substr(3,9)<<" ";
			double s=countbill(temp[i],temp[i+1]);
			printf("$%.2f\n",s);
			total+=s;
			}
			printf("Total amount: $%.2f\n",total);
	

		}
}
