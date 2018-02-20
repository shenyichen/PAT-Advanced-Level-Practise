#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int> > dis;
int maxsize;
int n,m,k,d_s,tdis,cmin;
float caverage;
vector<int> result;
struct canbe{
	vector<int> result;
	float average;
	int min,index;
	canbe(vector<int> result,int min,float average,int index):result(result),min(min),average(average),index(index){
	}
	
	bool operator <(const canbe &A)const{
		if(min==A.min)
		{
			
		
		if(average==A.average)
		return index<A.index;
		
		
	
		else return average<A.average;
	}else return min>A.min;
	}
};
vector<canbe> canbes;
bool dijkstra(int p)
{
	int cnt=0;
	cmin=INT_MAX;
	caverage=0;
	result.assign(maxsize,INT_MAX);
	vector<bool> visit(maxsize,false);
	result[p]=0;
	visit[p]=true;
	int tmp=INT_MAX,u=-1;
	for(int i=1;i<maxsize;i++)
	{
		if(i==p) continue;
		result[i]=dis[p][i];
		if(result[i]<tmp)
		{
			u=i;
			tmp=result[i];
		}
	}
	if(u<=n)
	{
	if(tmp>d_s) return false;
	if(cmin>tmp) cmin=tmp;
	if(tmp!=INT_MAX)
	{
		caverage+=tmp;
		cnt++;
	}
	}
	
	visit[u]=true;
	for(int i=0;i<maxsize-3;i++)
	{
		for(int j=1;j<maxsize;j++)
		{
			if((dis[u][j]+result[u])<result[j] && dis[u][j]!=INT_MAX && !visit[j])
			result[j]=dis[u][j]+result[u];

		}
		tmp=INT_MAX;
		u=-1;
		for(int j=1;j<maxsize;j++)
		{
			if(result[j]<tmp && !visit[j])
			{
			u=j;
			tmp=result[j];
			}
		}
		visit[u]=true;
		if(u<=n)
	{
	if(tmp>d_s) return false;
	if(cmin>tmp) cmin=tmp;
	if(tmp!=INT_MAX)
	{
		caverage+=tmp;
		cnt++;
	}
	}
	}
	caverage/=(cnt*1.0);
	return true;

}


int main()
{

	cin>>n>>m>>k>>d_s;
	maxsize=n+m+1;
	vector<int> tmpdis(maxsize,INT_MAX);
	dis.assign(maxsize,tmpdis);
	string tmp1,tmp2;
	int l1,l2;
	for(int i=0;i<k;i++)
	{
		cin>>tmp1>>tmp2>>tdis;
		if(tmp1[0]=='G')
		{
			tmp1=tmp1.substr(1);
			l1=atoi(tmp1.c_str())+n;
		}else l1=atoi(tmp1.c_str());
		
		if(tmp2[0]=='G')
		{
			tmp2=tmp2.substr(1);
			l2=atoi(tmp2.c_str())+n;
		}else  l2=atoi(tmp2.c_str());
		
		dis[l1][l2]=tdis;
		dis[l2][l1]=tdis;
	}
	for(int i=n+1;i<maxsize;i++)
	if(dijkstra(i)) canbes.push_back(canbe(result,cmin,caverage,i-n));
	if(canbes.size()==0)
	{
		cout<<"No Solution";
		return 0;
	}

	sort(canbes.begin(),canbes.end());
	printf("G%d\n%d.0 %.1f",canbes[0].index,canbes[0].min,canbes[0].average);
	
}
