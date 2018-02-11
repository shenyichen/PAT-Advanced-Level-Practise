#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> orig,lower,higher;

int main()
{
	int n,m,tmp;
	cin>>n>>m;
	while(n--)
	{
		scanf("%d",&tmp);
		orig.push_back(tmp);
	}
	sort(orig.begin(),orig.end());
	
	vector<int>::iterator max=upper_bound(orig.begin(),orig.end(),m);
	int mid=lower_bound(orig.begin(),max,m/2)-orig.begin();
	int i=0;
	
	for(;i<mid;i++)
	
	{
		if(i==0 || orig[i]!=lower.back())
		lower.push_back(orig[i]);
	}
	if(orig[mid]==orig[mid+1])
	{
		lower.push_back(orig[mid]);
		higher.push_back(orig[mid]);
		i=mid+2;
	}else{
			higher.push_back(orig[mid]);
			i=mid+1;
	}
	
	
	for(;i<max-orig.begin();i++)
	
	{
		if(orig[i]!=higher.back())
		higher.push_back(orig[i]);
	}
	
	for(i=0;i<lower.size();i++)
	{
		for(int j=0;j<higher.size();j++)
		{
			if(lower[i]+higher[j]==m)
			{
				cout<<lower[i]<<" "<<higher[j];
				return 0;
			}
		}
	}
	cout<<"No Solution";
}

