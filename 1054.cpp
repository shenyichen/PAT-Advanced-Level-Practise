#include<iostream>
#include<map>
using namespace std;
map<int,int> count;
int main(){
	int n,m,tmp,sum;
	cin>>n>>m;
	sum=(m*n)/2;
	while(m--)
	{
	for(int i=0;i<n;i++)
	{
	
			scanf("%d",&tmp);

		
			if(count.count(tmp)==0)
			count[tmp]=1;
			else 
			{
				count[tmp]++;

			}
			
							if(count[tmp]>sum)
				{
						cout<<tmp;
						return 0; 
				} 

		
		}
	}
	

	
} 
