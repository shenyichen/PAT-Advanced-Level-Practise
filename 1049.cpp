#include<iostream>
using namespace std;
int findone(int num){
	int k=1,count=0,cur,left=1,right;
	
	while(left>0){
		cur=(num/k)%10;
		left=num/(k*10);
		right=num-left*(k*10)-cur*k;
		switch(cur){
			case 0:count+=left*k;break;
			case 1:count+=left*k+right+1;break;
			default:count+=(left+1)*k;
		}
		k*=10;
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	cout<<findone(n);
}
