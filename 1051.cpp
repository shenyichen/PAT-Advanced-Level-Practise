#include<iostream>
#include<stack>
using namespace std;
stack<int> list;
int main(){
	int m,n,k,tmp;
	cin>>m>>n>>k;
	while(k--)
	{
		int o,index=1,i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			o=tmp-index+1;
			if(list.size()==0 || tmp>list.top())
			{
				if(o+list.size()<=m && index<=n)
				{
					
					for(int j=index;j<tmp;j++)
					list.push(j);
					index=tmp+1;
				}else{
					cout<<"NO"<<endl;
					break;
				} 
			}else if(tmp==list.top()){			
				list.pop();
			}else{
					cout<<"NO"<<endl;
					break;
				} 

		}
		if(i==n)
		cout<<"YES"<<endl;
		else{
			for(int j=1;j<n-i;j++)
			scanf("%d",&tmp);
		}	
		while(!list.empty()) list.pop();
	}
}
