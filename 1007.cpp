#include <cstdio>
#include <iostream>

using namespace std;
int flag=0;
int main()
{
	int k,temp=0,sum=-1,temi=0,left=0,right=0;
	
	cin>>k;
	int num[k];
	for(int i=0;i<k;i++)
	{
	
		cin>>num[i];
		if(num[i]>=0) flag=1;
		temp+=num[i];
		if(temp>sum){
			sum=temp;
			left=temi;
			right=i;
		
		}else if(temp<0)
		{
			temp=0;
			temi=i+1;
		}
		
	}
	
	if(flag==0) cout<<"0 "<<num[0]<<" "<<num[k-1];
	else
	{
		cout<<sum<<" "<<num[left]<<" "<<num[right];
	 } 
}
