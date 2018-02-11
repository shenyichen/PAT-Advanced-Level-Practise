#include<iostream>
using namespace std;

int chain[100001],resulti[100000000],resultj[100000000];

int main()
{
	int n,m,min,cnt;
	scanf("%d %d",&n,&m);
	min=m;
	int last=1,first=0;
	for(int i=0;i<n;i++)
	{ 

		int tmp;
		scanf("%d",&tmp);
		chain[i]=tmp;
	} 
	int tmp=chain[0];
	int j,i;
	for(i=0;i<n;i++)
	{
		i=max(i,first);
		
		for(j=i+last;j<=n;j++)
		{	
			int q=tmp-m;
			if(q<0)tmp+=chain[j];
			else if(q<=min)
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
				for(int k=i;k<j;k++)
				{
					tmp-=chain[k];
					if(tmp-m<=min)
					{
						first=k+1;
						break;
					}
					
				}
				last=j-first;
			
				break;
			}else 
			
			{
				for(int k=i;k<j;k++)
				{
					tmp-=chain[k];
					if(tmp-m<=min)
					{
						first=k+1;
						break;
					}
				}
				last=j-first;
				break;
			}
			
			
		}
		
		
	}
	for(int i=0;i<cnt;i++)
	{
		printf("%d-%d\n",resulti[i],resultj[i]);
	}
}
