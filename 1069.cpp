#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num(10,0);
int main()
{
	int realnumber1,realnumber2,num3,p=4;
	string n;
	cin>>n;
	
	for(int i=0;i<n.size();i++)
	{
		num[n[i]-'0']++;
		p--;
		if(num[n[i]-'0']==4)
		{
			cout<<n<<" - "<<n<<" = 0000";
			return 0;
		} 
	}
	num[0]+=p;
	while(1)
	{

	realnumber1=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<num[i];j++)
		{
			realnumber1*=10;
			realnumber1+=i;
			
		}
	}
		realnumber2=0;
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<num[i];j++)
		{
			realnumber2*=10;
			realnumber2+=i;
			
		}
	}
	num3=realnumber2-realnumber1;
	printf("%04d - %04d = %04d\n",realnumber2,realnumber1,num3);
	if(num3==6174)
	return 0;
	num.assign(10,0);
	p=4;
	while(num3>0)
	{
		num[num3%10]++;
		num3/=10;
		p--;
	}
	num[0]+=p;
	}
	
}
