#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
struct cus{
	int atime,ptime;
	cus(int a,int p):atime(a){
	 if(p>60) ptime=3600;
	 else ptime=p*60;
	 
	}
}; 
int wc;
double sum=0;
vector<cus> c; 
priority_queue<int,vector<int>,greater<int> >window;


bool cmp(cus A,cus B)
{
	return A.atime<B.atime;
}
int main(){
	string a;
	int m,t,p;
//	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1017.txt","r",stdin);
	cin>>m>>wc;
	for(int i=0;i<wc;i++) 
	window.push(28800);
	while(m--)
	{
	cin>>a>>p;
	t=0;
	t+=((a[0]-'0')*10+a[1]-'0')*3600;
	t+=((a[3]-'0')*10+a[4]-'0')*60;
	t+=((a[6]-'0')*10+a[7]-'0');
	if(t<61201) c.push_back(cus(t,p));
	}
	sort(c.begin(),c.end(),cmp);
	for(int i=0;i<c.size();i++)
	{
		if(c[i].atime<=28800)
		{
		sum+=28800-c[i].atime;
		c[i].atime=28800;
		}

		int min=window.top();
		window.pop();
		
		if(min<=c[i].atime) min=c[i].atime+c[i].ptime;
		else{
		sum+=min-c[i].atime;
		min+=c[i].ptime;
		
		}
		window.push(min);

	}
	
	printf("%.1f",sum/c.size()/60.0);
	
}
