#include<iostream>
#include<vector>
using namespace std;
vector<int> dis;

int main(){
	int n,tmp,m,i,j=0,min;
	scanf("%d",&n);
	dis.push_back(0);
	for(i=0;i<n-1;i++)
	{	
		scanf("%d",&tmp);
		j+=tmp;
		dis.push_back(j);
		
	}
	scanf("%d",&tmp);
	dis.push_back(tmp);
	scanf("%d",&m);
	while(m--)
	{
		
		scanf("%d %d",&i,&j);
		if(j<i)
		{
			tmp=i;
			i=j;
			j=tmp;
			
		}
		min=dis[j-1]-dis[i-1];
		tmp=dis[i-1]+dis[n]+dis[n-1]-dis[j-1];
		if(min>tmp)
		printf("%d\n",tmp);
		else printf("%d\n",min);

	}
	
	
	
}
