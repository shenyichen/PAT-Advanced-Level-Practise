#include<iostream>
#include<algorithm>
using namespace std;
string M[3]={"00","00","00"};
int main()
{
	for(int i=0;i<3;i++)
	{
		int a;
		cin>>a;
		int j=0;
		while(a>0)
		{
			int tem=a%13;
			if(tem>9) tem=tem-10+'A';
			else tem+='0';
			M[i].replace(j,1,1,tem);
			a/=13;
			j++;
		}
		reverse(M[i].begin(),M[i].end());
		
	}
	cout<<"#"<<M[0]<<M[1]<<M[2];
	
}
