#include<iostream>
using namespace std;
float w[3],t[3],l[3],maxp=1;
int main(){
for(int i=0;i<3;i++) cin>>w[i]>>t[i]>>l[i];

for(int i=0;i<3;i++)
{
	if(w[i]>t[i]) 
	{
		cout<<"W ";
		maxp*=w[i];
	}
	else if(t[i]>l[i]) {
		cout<<"T ";
		maxp*=t[i];
			}
	else 
	{
		cout<<"L ";
		maxp*=l[i];
	}
	
	}
	
maxp=((maxp*0.65)-1)*2;
printf("%.2f",maxp);

} 
