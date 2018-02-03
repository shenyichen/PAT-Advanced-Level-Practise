#include<iostream>
#include<cmath>
using namespace std;

long int reverse(long int i,int radix)
{
			long int tem=0;
	if(radix==10)
	{

		while(i>0)
		{
		tem=i%10+tem*10; 
		i/=10;	
		}
		return tem;
	}
	
	string a;

while(i>0)
{
			a+=i%radix+'0';
		i/=radix;

}	
	a+='\0';
	int t;
	t=a.length()-1;
	for(int j=0;j<t;j++)
	{
	tem+=pow(radix,t-j-1)*(a[j]-'0');
	 } 
 	return tem;
}

bool isPrime(long int i)
{
	if(i<2) return 0;
	int tem=sqrt(i);
	for(int j=2;j<=tem;j++)
	{
		if(i%j==0) return 0;

	}
	return 1;
}
int main()
{
while(1)
{
	long int a,b;
	cin>>a;
	if(a<0) return 0;
	cin>>b;
	if(isPrime(a)==1)
	{
		long int c=reverse(a,b);
		if(isPrime(c)==1)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		
		
	}
	cout<<"No"<<endl;
}
}
