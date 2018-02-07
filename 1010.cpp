#include<iostream>
#include<cstdio>
using namespace std;
string N1,N2;
long long int n1,n2,low,high;

long long int trans2ten(string N,int k)
{
	long long int result=0;
	int  t=N.size();
	for(int i=0;i<t;i++)
	{
		if(N[i]>='0' && N[i]<='9') result=result*k+(N[i]-'0');
		else result=result*k+(N[i]-'a'+10);
	}
	
	return result;
}

int cmp(string N,int k,long long int target)
{
	long long int result=0;
	int  t=N.size();
	for(int i=0;i<t;i++)
	{
		if(N[i]>='0' && N[i]<='9') result=result*k+(N[i]-'0');
		else result=result*k+(N[i]-'a'+10);
		if(result>target || result<0) return 1;
			
}
if(result==target) return 0;
if(result<target) return -1;	
}



long long int binsearch(long long int low,long long int high,long long int n1,string N2)
{
	while(low<=high)
	{
		long long int mid=(low+high)/2;
		int n2=cmp(N2,mid,n1);
		if(n2==0) 
		{
			cout<<mid;
			return 0;
		}
		if(n2==1) high=mid-1;
		if(n2==-1) low=mid+1;
	}
	
	cout<<"Impossible";
}
int main()
{
	int tag,radix;
//	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1010.txt","r",stdin);
	cin>>N1>>N2;
	cin>>tag>>radix;

	if(tag==2) swap(N1,N2);
	low=0;
	for(int i=0;i<N2.size();i++)
	{
		if(N2[i]>='0' && N2[i]<='9'){
			if(N2[i]-'0'>low) 
		{
			low=N2[i]-'0';
			
		}
		}else{
			if(N2[i]-'a'+10>low) 
		{
			
			low=N2[i]-'a'+10;
			
		}
		}

		
	}
	low++;
	if(low==0) 
	{
	cout<<"Impossible";
	return 0;
	}
	n1=trans2ten(N1,radix);
	n2=trans2ten(N2,low);
	if(n1<n2) 
	{
	cout<<"Impossible";
	return 0;
	}
	high=max(low,n1)+1;
	binsearch(low,high,n1,N2);
 } 
