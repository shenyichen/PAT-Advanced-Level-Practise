#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> num;
map<int,int>count;


int main()
{
	int n;
	cin>>n;
	while(n--){
		int p;
		scanf("%d",&p);
		if(count.find(p)!=count.end())
		count[p]++;
		else count[p]=1;
		num.push_back(p);
	}
	for(int i=0;i<num.size();i++)
	{
		if(count[num[i]]==1)
		{
			cout<<num[i];
			return 0;
		}
		
	}
cout<<"None";

}
