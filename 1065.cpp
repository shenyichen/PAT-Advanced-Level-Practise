#include<iostream>
using namespace std;
long long int a,b,c;
int main()
{
	int n;
	cin>>n;
for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #%d: ",i);
		if(a>=0 &&b>=0 &&c<0)
		{
			printf("true\n");
			continue;
		}
		
		if(a<=0 &&b<=0 &&c>=0)
		{
			printf("false\n");
			continue;
		}
		if((a>0 && b>0) || (a<0 &&b<0))
		{
		if(a>c-b)
		printf("true\n");
		else printf("false\n");
		continue;	
		}else{
		if(a+b>c)
		printf("true\n");
		else printf("false\n");
		continue;	
		}

				


		

	}
	
 } 
