#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long int> cpos,cnag,ppos,pnag;
bool cmp(long int &A,long int &B)
{
	return A>B;
 } 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long int tmp;
		scanf("%ld",&tmp);
		if(tmp>0) cpos.push_back(tmp);
		else cnag.push_back(tmp);
	}
	
	cin>>n;
	while(n--)
	{
		long int tmp;
		scanf("%ld",&tmp);
		if(tmp>0) ppos.push_back(tmp);
		else pnag.push_back(tmp);
	}
	sort(cpos.begin(),cpos.end(),cmp);
	sort(ppos.begin(),ppos.end(),cmp);
	sort(cnag.begin(),cnag.end());
	sort(pnag.begin(),pnag.end());
	int m;
	long int sum=0;
	n=min(cpos.size(),ppos.size());
	m=min(cnag.size(),pnag.size());
	for(int i=0;i<n;i++)
	sum+=cpos[i]*ppos[i];
	for(int i=0;i<m;i++)
	sum+=cnag[i]*pnag[i];
	printf("%ld",sum);
	
}
