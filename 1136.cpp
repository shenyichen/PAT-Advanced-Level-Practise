#include<iostream>
#include<cstring>
using namespace std;
int flag=0;
char A[1010],B[1010],C[1010],tem,D[1010];
int main(){
	
cin>>A;
for(int i=0;i<10;i++)
{
	int tag=0,len;
	len=strlen(A)-1;
	for(int j=len;j>=0;j--)
	{
		B[tag++]=A[j];
	}
	B[tag]='\0';
	for(int k=0;k<=len;k++)
	{
		
		if(A[k]==A[len-k])flag=1;
		else 
		{
			flag=0;
			break;
		}
	 }
	 if(flag==1) 
	 {
	 cout<<A<<" is a palindromic number.";
	 return 0;
	 }
	 int k=0,flag=0;
	 for(;k<=len;k++)
	 {
	 	if(flag==1)
		 {
		 tem=A[k]+B[k]-'0'+1;
		 flag=0;	
		 }else tem=A[k]+B[k]-'0';
	 	
	 	if(tem<='9')C[k]=tem;
	 	else
	 	{
	 		C[k]=tem-10;
	 		flag=1;
		 }

		
	 }
	 if(flag==1)
	 {
	 	C[k]='1';
	 	C[k+1]='\0';
	 }
		else	C[k]='\0'; 
	tag=0;	
	len=strlen(C)-1;
	for(int j=len;j>=0;j--)
	{
		D[tag++]=C[j];
	}
	D[tag]='\0';
	 cout<<A<<" + "<<B<<" = "<<D<<endl; 
	 strcpy(A,D);
}
cout<<"Not found in 10 iterations.";
}
