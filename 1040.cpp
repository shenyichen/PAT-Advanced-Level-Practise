#include<iostream>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int max=1;
	int size=str.size();

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			int tmp=i+j;
			bool flag=false;
			int k=0;
			if(tmp%2==0){
				tmp/=2;
			for(;(tmp-k)>=i;k++)	
				
			if(str[tmp+k]!=str[tmp-k])
			{
				flag=true;
				break;
			}
			
				
				if(!flag)
			{
				if(j-i+1>max)
				max=j-i+1;
			}		
			}else {
				tmp/=2;
			for(;(tmp-k)>=i;k++)
			{
				if(str[tmp+k+1]!=str[tmp-k])
					{
				flag=true;
				break;
					}
			}
				
				if(!flag)
			{
				if(j-i+1>max)
				max=j-i+1;
			}	
			}

			}
		}
		

		cout<<max<<endl; 
	}

