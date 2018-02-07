#include<iostream>
using namespace std;
int N,M;
int C[30];
int main(){
	cin>>N>>M;
	if(N==0)
	{
		cout<<"Yes"<<endl<<"0";
		return 0;
	}
	
	int i=0;
	while(N>0)
	{
		C[i]=N%M;
		
		N/=M;
		i++;
	}
	
	int s=i;
	for(int k=0;k<s/2;k++)
	{
		if(C[k]!=C[s-k-1])
		{

     cout<<"No"<<endl<<C[s-1];
      while(s-->1)
      {
        cout<<" "<<C[s-1];
       } 
       return 0;
		}
		
		
		
	}
	
		cout<<"Yes"<<endl<<C[s-1];
     while(s-->1)
      {
        cout<<" "<<C[s-1];
       } 
			 return 0;
}
