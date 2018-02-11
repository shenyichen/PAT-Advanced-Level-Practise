#include<iostream>
using namespace std;

int chain[100001],resulti[100000000],resultj[100000000];

int main()
{
	int n,m,min,cnt;
	scanf("%d %d",&n,&m);
	min=m;
	for(int i=0;i<n;i++)
	{ 

		int tmp;
		scanf("%d",&tmp);
		chain[i]=tmp;
	} 
	int j=0,i=0,tmp=0;
	while(i<n)
	{
		int q=tmp-m;
		while(q<0  && j<n)	
		{	
			tmp+=chain[j];
			j++;
			q=tmp-m;	
		}

		if(q<=min &&q>=0)
			{

				if(q==min)
				{
					resulti[cnt]=i+1;
					resultj[cnt]=j;
					cnt++;
				}

				else{
					cnt=0;
					resulti[cnt]=i+1;
					resultj[cnt]=j;
					cnt++;
					min=q;
				}
				for(int k=i;k<=j;k++)
				{
					tmp-=chain[k];
					if(tmp-m<=min)
					{
						i=k+1;
						break;
					}
					
				}
				
			
			}else 
			
			{
				for(int k=i;k<=j;k++)
				{
					tmp-=chain[k];
					if(tmp-m<=min)
					{
						i=k+1;
						break;
					}
				}
			}
	}
	
	for(int i=0;i<cnt;i++)
	{
		printf("%d-%d\n",resulti[i],resultj[i]);
	}
}
