#include<iostream>
using namespace std;
int main()
{
	string n;
	cin>>n;
	int N=n.size();
	int n1max=0;
	for(int n2=3;n2<=N;n2++)
	{
		for(int n1=0;n1<=n2;n1++)
		{
		
		if(2*n1+n2-2==N)
		{
		if(n1>n1max)
		n1max=n1;
		}
		}
	 } 
	 int n2=N+2-2*n1max;
	 for(int i=0;i<n1max-1;i++)
	 {
	 	cout<<n[i];
	 	for(int j=0;j<n2-2;j++)
	 	cout<<" ";
	 	cout<<n[N-i-1]<<endl;
	 }
	 cout<<n[n1max-1];
	 for(int i=n1max;i<n1max+n2-1;i++)
	 {
	 	cout<<n[i];
	 }
 } 
