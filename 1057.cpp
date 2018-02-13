#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define lowbit(i) ((i)&(-i))
using namespace std;
int c[100010];
stack<int> s;

void add(int x,int y)
{
	for(int i=x;i<100010;i+=lowbit(i))
	{
		c[i]+=y;
	}
}

int getsum(int x)
{
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))
	{
		sum+=c[i];
	}
	return sum;
}

int binarysearch(int left,int right,int k)
{
	int mid;
	int sum;
	while(left<right)
	{
		mid=left+(right-left)/2;
		sum=getsum(mid);
		if(sum>=k) right=mid;
		else left=mid+1;
	}
	return left;
	
}
int main()
{
	int k,num;
	string commnd;
	commnd.resize(11);
	cin>>k;
	while(k--)
	{
		scanf("%s",&commnd[0]);
		if(commnd[1]=='u')
		{
			scanf("%d",&num);
			s.push(num);
			add(num,1);
			
		}else if(commnd[1]=='o')
		{	
			if(s.size()!=0)
			{	
				cout<<s.top()<<endl;
				add(s.top(),-1);
				s.pop();
				
			}else printf("Invalid\n");
			
		}else{
			
				if(s.size()!=0)
			{
				printf("%d\n",binarysearch(1,100010,(s.size()+1)/2));

			} else printf("Invalid\n");
		}
	}
}
