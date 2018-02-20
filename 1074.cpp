#include<iostream>
#include<vector>
using namespace std;
struct node{
	int next,number,last;
	node(int number,int next,int last):number(number),next(next),last(last){
	}
};

vector<node> linklist(100001,node(-1,-1,-1));
int main(){
	int first,sum,n,tmp,t,q,s,nn;
	cin>>first>>sum>>n;
	int current,num,next;
	while(sum--)
	{
		scanf("%d %d %d",&current,&num,&next);
		linklist[current].next=next;
		linklist[current].number=num;
	}
	q=0;
	tmp=first;
	while(tmp!=-1)
	{
		q++;
		tmp=linklist[tmp].next;
	}
	q/=n;
	tmp=first;
	for(int j=0;j<q;j++){
	
	
	for(int i=0;i<n-1 && tmp!=-1;i++)
	{
		t=tmp;
		tmp=linklist[tmp].next;
		linklist[tmp].last=t;
		
	}


	nn= linklist[tmp].next;
	if(j==0)first=tmp;
	else linklist[s].next=tmp;
	for(int i=0;i<n-1 && linklist[tmp].last!=-1;i++)
	{
	
	linklist[tmp].next=linklist[tmp].last;
	tmp=linklist[tmp].last;
	}
	s=tmp;
	if(j==q-1)
	linklist[tmp].next=nn;
	tmp=nn;
	}
	
	tmp=first; 
while(tmp!=-1)
{
	if(linklist[tmp].next!=-1)
	printf("%05d %d %05d\n",tmp,linklist[tmp].number,linklist[tmp].next);
	else printf("%05d %d -1",tmp,linklist[tmp].number);
	tmp=linklist[tmp].next;
	
} 

}
