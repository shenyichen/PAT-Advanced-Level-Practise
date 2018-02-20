#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct cake{
	double price,profit,stock;
	
bool operator<(const cake &A)const
{
	return profit>A.profit;
}
	
};
vector<cake> cakes;

int main()
{
	int n,d,current;
	double money=0;
	cin>>n>>d;
	cakes.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&cakes[i].stock); 
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&cakes[i].price);
		cakes[i].profit=cakes[i].price/cakes[i].stock;
	}
	
	sort(cakes.begin(),cakes.end());
	int i=0;
	current=d;
	while(i<n)
	{
		if(cakes[i].stock<current)
		{
			current-=cakes[i].stock;
			money+=cakes[i].price;
		}else{
			
			money+=cakes[i].price*(current*1.0/cakes[i].stock);
			break;
		}
		
		i++;
	} 
	printf("%.2f",money);
}
