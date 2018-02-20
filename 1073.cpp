#include<iostream>
using namespace std;
int main()
{
	string n;
	cin>>n;
	if(n[0]=='-')
	cout<<"-";
	int i=1;
	while(n[i]=='0')
	i++;
	int p=i;
	for(;p<n.size();p++)
	if(n[p]=='.')
	break;
	int front=p-i;
	p++;
	for(;p<n.size();p++)
	if(n[p]=='E')
	break;
	int last=p-front-2;
	p++;
	bool flag;
	if(n[p]=='-')
	flag=false;
	else flag=true;
	p++;
	int E=0;
	for(;p<n.size();p++)
	{
		E*=10;
		E+=n[p]-'0';
	}
	if(E==0) flag=true;
	int q;
	if(flag)
	{
		if(E>last)
		{
		for(q=1;q<last+3;q++)
		if(n[q]!='.')
		cout<<n[q];
		for(q=0;q<E-last;q++)
		cout<<0;
		}else
		{
			for(q=1;q<E+3;q++)
			if(n[q]!='.')
			cout<<n[q];
			if(E!=last)cout<<'.';
			for(;q<last+3;q++)
			cout<<n[q];
			
		}

	}else{
		cout<<"0.";
		for(q=0;q<E-1;q++)
		cout<<0;
		cout<<n[1];
		for(q=3;q<last+3;q++)
		cout<<n[q];
		
		
	}
	
	
	
}
