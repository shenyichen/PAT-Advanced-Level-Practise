#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> c,res;
vector<vector<int> > d;
vector<vector<bool> > has;

bool cmp(const int &A,const int &B){
	return A>B;
}


int caculatemax(int sum,int target)
{
	int tmp;
	for(int i=1;i<=sum;i++)
	{
		for(int j=c[i];j<=target;j++)
		{
			
			tmp=d[i-1][j-c[i]]+c[i];
			if(tmp<d[i-1][j])
			d[i][j]=d[i-1][j];
			else{
				d[i][j]=tmp;
				has[i][j]=true;
			} 
		}
	}
	return d[sum][target];
}


int main(){
	int n,k;
	cin>>n>>k;
	c.resize(n+1);
	c[0]=0;
	d.assign(n+1,vector<int>(k+1,0));
	has.assign(n+1,vector<bool>(k+1,false));
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	sort(c.begin()+1,c.end(),cmp);
	
	if(caculatemax(n,k)==k)
	{
		while(k)
		{
			while(!has[n][k])
			n--;
			res.push_back(c[n]);
			k-=c[n];
			n--;
			
		}
		
		cout<<res[0];
		for(int i=1;i<res.size();i++)
		cout<<" "<<res[i];
		return 0;
		
		
	}else cout<<"No Solution";
		

}
