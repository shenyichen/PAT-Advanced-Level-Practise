#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct pairinfo{
	int arrival,playtime,start,haveserved;
	bool vip;
	pairinfo(int arrival,int playtimed,bool vip,bool haveserved):arrival(arrival),vip(vip),haveserved(haveserved){		
	playtime=playtimed*60;
	}

};
struct tableinfo{
	int endtime,count,id;
	bool vip;
	tableinfo(int endtime,int count,bool vip,int id):endtime(endtime), count(count),vip(vip),id(id){	
	}
	bool operator < (const tableinfo &A)const
	{
		return endtime<A.endtime;
	}
};
vector<pairinfo> pairs;
vector<tableinfo>tables;
bool cmpa(const pairinfo &A,const pairinfo &B){
		return A.arrival<B.arrival;
}
bool cmps(const pairinfo &A,const pairinfo &B){
		return B.start<B.start;
}

int main()
{
	bool vip;
	int n;
	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1026.txt","r",stdin);
	cin>>n;
	while(n--)
	{
		int h,m,s,p;
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		cin>>vip;
		pairs.push_back(pairinfo(h*3600+m*60+s,p,vip,false));
	}
	int k,m;
	cin>>k>>m;

	for(int i=1;i<=k;i++)
	{
	tables.push_back(tableinfo(28800,0,false,i));
	}


	while(m--)
	{
		cin>>k;
		tables[k-1].vip=k;
	}
	sort(pairs.begin(),pairs.end(),cmpa);
	for(int i=0;i<pairs.size();i++)
	{
		if(pairs[i].haveserved) continue;	
		sort(tables.begin(),tables.end());
		if(tables[0].vip)
		{
			for(int j=0;j<pairs.size();j++)
			{
				if(pairs[j].vip &&pairs[j].arrival>=tables[0].endtime)
				{
					if(tables[0].endtime>=pairs[j].arrival)
					tables[0].endtime+=pairs[j].playtime;
					else tables[0].endtime=pairs[j].playtime+pairs[j].arrival;
					pairs[j].start=tables[0].endtime-pairs[j].playtime;
					i--;
					break;
				}
				if(j==pairs.size()-1)
				{
				if(tables[0].endtime>=pairs[i].arrival)
				tables[0].endtime+=pairs[i].playtime;
				else tables[0].endtime=pairs[i].playtime+pairs[i].arrival;
				pairs[i].start=tables[0].endtime-pairs[i].playtime;
				
				}
				
			}
		}else{
			if(tables[0].endtime>=pairs[i].arrival)
			tables[0].endtime+=pairs[i].playtime;
			else tables[0].endtime=pairs[i].playtime+pairs[i].arrival;
			pairs[i].start=tables[0].endtime-pairs[i].playtime;
		}
	}
	sort(pairs.begin(),pairs.end(),cmps);
	for(int i=0;i<pairs.size();i++)
	{
		if(pairs[i].start<75600)
		{
		int h,m,s,tem;
		tem=pairs[i].arrival;
		h=tem/3600;
		tem-=h*3600;
		m=tem/60;
		s=tem-m*60;
		printf("%02d:%02d:%02d ",h,m,s);
		tem=pairs[i].start;
		h=tem/3600;
		tem-=h*3600;
		m=tem/60;
		s=tem-m*60;
		printf("%02d:%02d:%02d ",h,m,s);
		int wait=(pairs[i].start-pairs[i].arrival+30)/60;
		cout<<wait<<endl;
		}

	}
}
