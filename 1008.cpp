#include<iostream>
using namespace std;

int currentlevel=0,targetlevel,totaltime,tem;
int main(){
	int k;
	cin>>k;
	totaltime=k*5;
	while(k--)
	{
		cin>>targetlevel;
		tem=targetlevel-currentlevel;
		if(tem) totaltime+=tem*6;
		else totaltime-=tem*4;
		currentlevel=targetlevel;
	}
	cout<< totaltime;
	
}
