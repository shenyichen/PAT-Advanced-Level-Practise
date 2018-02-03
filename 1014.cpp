#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M,K,Q,count=0;
struct window{
	int poptime,pushtime,over;
	queue<int> q;
	window(int poptime=0,int pushtime=0,int over=0):poptime(poptime),pushtime(pushtime),over(over){
	}
}; 
int main()
{
	int a,b,c,d,e;
	vector<int> t;
	vector<window> win;
//	freopen("E:\\cs2018\\PAT\\testcase\\1014.txt","r",stdin);
	cin>>N>>M>>K>>Q;
	for(int i=0;i<N;i++) win.push_back(window());	
	for(int i=0;i<K;i++)
	{

		cin>>a;

		if(i<M*N)
		{
			b=(i)%N;
		if(win[b].over==0 && count!=N)
		{
				if(win[b].pushtime+a>=540)
				{
				count++;
				win[b].over=1;
				}
				win[b].q.push(a);
				win[b].poptime=win[b].q.front();
				t.push_back(a+win[b].pushtime);
				win[b].pushtime+=win[b].q.back();

		}else 
		{ t.push_back(-1);
		} 
		continue;
			
		}
		
				b=0;
			for(int j=1;j<N;j++)
		{
			if(win[j].poptime<win[b].poptime)
			{
			b=j;	
			}
			
		}


		
		if(win[b].over==0 && count!=N)
		{
		if(win[b].pushtime+a>=540)
				{
				count++;
				win[b].over=1;

				}
				win[b].q.pop();
				win[b].q.push(a);
				win[b].poptime+=win[b].q.front();
				t.push_back(a+win[b].pushtime);
				win[b].pushtime+=win[b].q.back();

 
				

		}else
		{ t.push_back(-1);
			win[b].q.pop();
			win[b].poptime+=win[b].q.front();
		} 
	}


	while(Q--)
	{
		cin>>a;
		a--;
		b=t[a];
		if(b==-1)cout<<"Sorry"<<endl;
		else{
		b+=480;		
		d=b%60;
		e=b/60;		
		printf("%02d:%02d\n",e,d);
			}
	}
}
