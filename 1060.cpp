#include<iostream>
#include<vector>
using namespace std;
vector<int> digit1,digit2;
int main()
{
	int n,tmp,n1,n2,t,c1=999,c2=999;
	string d1,d2,out1,out2;
	cin>>n>>d1>>d2;
	n1=d1.length();
	n2=d2.length();
	t=0;
	while(d1[t]=='0')
	{
		t++;
		if(d1[t]=='.')
		{
			c1=t;
			t++;
		}
		
		
	}
	c1=t-c1-1;
	for(int i=t;i<d1.length();i++)
	{

		tmp=d1[i]-'0';
		if(tmp>=0)
		{
			digit1.push_back(tmp);
		}else n1=i-t;

	
	}
	if(c1>=0) n1=c1;
	if(digit1.size()==0)
	n1=0;
	t=0;
	while(d2[t]=='0')
	{
		t++;
		if(d2[t]=='.')
		{
			c2=t;
			t++;
		}
		
		
	}
	c2=t-c2-1;
		for(int i=t;i<d2.length();i++)
	{
	

		tmp=d2[i]-'0';
		if(tmp>=0)
		{
			digit2.push_back(tmp);
		}else n2=i-t;
	
	}
	if(c2>=0 !=0) n2=c2;
	if(digit2.size()==0)
	n2=0;
	out1="0.";
	for(int i=0;i<n;i++)
	{		
	if(i>=digit1.size())
	out1+='0';
	else out1+=digit1[i]+'0';
		}
	out1+="*10^";
	if(c1>0 &&n1!=0)
	out1+="-";
	out2="0.";	
	for(int i=0;i<n;i++)
	{
	if(i>=digit2.size())
	out2+='0';
	else out2+=digit2[i]+'0';
	}

	out2+="*10^";
	if(c2>0 &&n2!=0)
	out2+="-";
	if(out1==out2)
	{
		cout<<"YES";
	printf(" %s%d",out1.c_str(),n1);
	return 0;
	}
	else cout<<"NO";
	printf(" %s%d %s%d",out1.c_str(),n1,out2.c_str(),n2);
 } 
