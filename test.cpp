#include<stdio.h>
int main()
{
	int k=0;
	float a[1001];
	int g;
	float tem;
	for(int i=0;i<=1000;i++) a[i]=0; 
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %f",&g,&tem);
		a[g]=tem;
	}
	
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %f",&g,&tem);
		a[g]+=tem;
	}
	k=0;
	for(int i=0;i<=1000;i++)
	{
		if(a[i]!=0) k++;
	}
	printf("%d",k);
	if(k!=0) printf(" ");
	int q=0;
	for(int i=1000;i>=0;i--)
	{
		if(a[i]!=0) {
		q++;
		if(q==k)printf("%d %.1f",i,a[i]);
		else printf("%d %.1f ",i,a[i]);
			}
	}
}
