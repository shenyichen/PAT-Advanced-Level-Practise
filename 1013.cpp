#include<iostream>
#include<cstring>
using namespace std;

int v[1001][1001]={0},visit[1001];
int N,M,K;
void dfs(int c)
{
		visit[c]=1;
		for(int j=0;j<N;j++)
		{
			if(v[c][j]==1 && visit[j]==0)
			{	
				dfs(j);
			}
		}

}
int main()
{
	int a,b;
	cin>>N>>M>>K;
	while(M--)
	{
		cin>>a>>b;
		a--;
		b--;
		v[a][b]=1;
		v[b][a]=1;
	}
	while(K--)
	{
		cin>>a;
		for(int i=0;i<N;i++) visit[i]=0;
		visit[a-1]=1;
		b=0;
		for(int i=0;i<N;i++)
		{
			if(visit[i]==0)
			{
				dfs(i);
				b++;
			}
		}
		cout<<b-1<<endl;
	}
}
