#include<iostream>
#include<vector>
using namespace std;
vector<int> list;
int main()
{
	int n,tmp,index=1,cnt=0,ans=0;
	cin>>n;
	list.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		list[tmp]=i;
		if(tmp!=i && tmp!=0) cnt++;
	}
	while(cnt>0)
	{
		if(list[0]==0)
		{
			while(list[index]==index &&index<n)
			index++;
			swap(list[0],list[index]);
			ans++;
		}else{
			



			swap(list[0],list[list[0]]);
			ans++;
			cnt--;
		}
	}
	cout<<ans;

}
