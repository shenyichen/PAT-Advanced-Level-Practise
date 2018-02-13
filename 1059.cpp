#include<iostream>
#include<vector>
using namespace std;
vector<int> prime;
vector<bool> isprime(60000,false);  
int main()  
{  
	int total=0;
  for(int i=2;i<60000;i++)
  {
  	
  	if(!isprime[i])
  	prime.push_back(i);
  	for(int j=0;j<prime.size() && prime[j]*i<60000;j++)
  	{
  		isprime[prime[j]*i]=true;
  		if(i%prime[j]==0) break;
  		
	  }
  }
  
  int num,cnt=0,flag=false;
  cin>>num;
  cout<<num<<"=";
  if(num==1) cout<<"1";
  for(int i=0;i<prime.size() && prime[i]<=num;i++)
  {
  	while(num%prime[i]==0)
  	{
  		cnt++;
		num/=prime[i];

	 }
	if(cnt!=0)
	{		if(flag)printf("*");
			else flag=true;
			printf("%d",prime[i]);
			if(cnt>1)
			printf("^%d",cnt);
			cnt=0;
	}
	 	
	 	

  }

}
