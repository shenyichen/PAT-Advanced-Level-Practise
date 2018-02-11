#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long int> number;
int main()
{
	long int a;
	scanf("%ld",&a);
	for(long int i=0;i<a;i++)
	{
		long int tem;
		scanf("%ld",&tem);
		number.push_back(tem);
	}
	scanf("%ld",&a);
	for(long int i=0;i<a;i++)
	{
		long int tem;
		scanf("%ld",&tem);
		number.push_back(tem);
	}
	 

	nth_element(number.begin(),number.begin()+(number.size()-1)/2,number.end()); 
	printf("%ld",number[(number.size()-1)/2]);
}
