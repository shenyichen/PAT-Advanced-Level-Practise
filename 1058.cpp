#include<iostream>
using namespace std;
int main()
{
	int g,s,k,tmp;
	scanf("%d.%d.%d ",&g,&s,&k);
	scanf("%d.",&tmp);
	g+=tmp;
	scanf("%d.",&tmp);
	s+=tmp;
	scanf("%d",&tmp);
	k+=tmp;
	int flag;
	flag=k/29;
	k%=29;
	s+=flag;
	flag=s/17;
	s%=17;
	g+=flag;
	printf("%01d.%01d.%01d",g,s,k);
}
