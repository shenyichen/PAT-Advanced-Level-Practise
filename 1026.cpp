#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct pairinfo{
	int arrival,playtime,start,wtime;
	bool vip,haveserved;
	pairinfo(int arrival,int playtimed,bool vip,bool haveserved,int wtime):arrival(arrival),vip(vip),haveserved(haveserved),wtime(wtime){		
	if(playtimed>=120) playtime=7200;
	else playtime=playtimed*60;

	}

};
struct tableinfo{
	int endtime,count,id;
	bool vip;
	tableinfo(int endtime,int count,bool vip,int id):endtime(endtime), count(count),vip(vip),id(id){	
	}
	bool operator < (const tableinfo &A)const
	{	if(endtime==A.endtime) 
		return id<A.id;
		else return endtime<A.endtime;
	}
};
vector<pairinfo> pairs;
vector<tableinfo>tables;
bool cmpa(const pairinfo &A,const pairinfo &B){

	return A.arrival<B.arrival;
		
}
bool cmps(const pairinfo &A,const pairinfo &B){
		return A.start<B.start;
}
bool cmpt(const tableinfo &A,const tableinfo &B){
		return A.id<B.id;
}

int main()
{
	bool vip;
	int n;
//	freopen("E:\\cs2018\\PAT\\testcase\\1026.txt","r",stdin);
	cin>>n;
	while(n--)
	{
		int h,m,s,p;
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		cin>>vip;
		pairs.push_back(pairinfo(h*3600+m*60+s,p,vip,false,0));
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
		if(pairs[i].arrival<28800)
		{
			pairs[i].wtime+=28800-pairs[i].arrival;
			pairs[i].arrival=28800;
		}
	}
	for(int i=0;i<pairs.size();i++)
	{
		if(pairs[i].haveserved) continue;	
		for(int j=0;j<tables.size();j++)
		{
		if(tables[j].endtime<pairs[i].arrival) tables[j].endtime=pairs[i].arrival;
		}
		sort(tables.begin(),tables.end());

		if(pairs[i].vip)
		{
			for(int j=0;j<tables.size();j++)
			{
				if(tables[j].endtime!=tables[0].endtime) break;
				if(tables[j].vip)
				{
					if(tables[j].endtime>=pairs[i].arrival)
					tables[j].endtime+=pairs[i].playtime;
					else tables[j].endtime=pairs[i].playtime+pairs[i].arrival;
					pairs[i].start=tables[j].endtime-pairs[i].playtime;
					pairs[i].haveserved=true;
					if(pairs[i].start<75600)tables[j].count++;
					break;
				}
			}
			if(pairs[i].haveserved) continue;	
		}
		if(tables[0].vip)
		{
			for(int j=0;j<pairs.size();j++)
			{
				if(pairs[j].vip &&pairs[j].arrival<=tables[0].endtime && !pairs[j].haveserved)
				{
					if(tables[0].endtime>=pairs[j].arrival)
					tables[0].endtime+=pairs[j].playtime;
					else tables[0].endtime=pairs[j].playtime+pairs[j].arrival;
					pairs[j].start=tables[0].endtime-pairs[j].playtime;
					pairs[j].haveserved=true;
					if(pairs[j].start<75600)tables[0].count++;
					i--;
					break;
				}
				if(j==pairs.size()-1)
				{
				if(tables[0].endtime>=pairs[i].arrival)
				tables[0].endtime+=pairs[i].playtime;
				else tables[0].endtime=pairs[i].playtime+pairs[i].arrival;
				pairs[i].start=tables[0].endtime-pairs[i].playtime;
				pairs[i].haveserved=true;
				if(pairs[i].start<75600)tables[0].count++;
				}
				
			}
		}else{
			if(tables[0].endtime>=pairs[i].arrival)
			tables[0].endtime+=pairs[i].playtime;
			else tables[0].endtime=pairs[i].playtime+pairs[i].arrival;
			pairs[i].start=tables[0].endtime-pairs[i].playtime;
			pairs[i].haveserved=true;
			if(pairs[i].start<75600)tables[0].count++;
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
		int wait=(pairs[i].start-pairs[i].arrival+30+pairs[i].wtime)/60;
		cout<<wait<<endl;
		}

	}
	sort(tables.begin(),tables.end(),cmpt);
	cout<<tables[0].count;
	for(int i=1;i<tables.size();i++)
	cout<<" "<<tables[i].count;
}
