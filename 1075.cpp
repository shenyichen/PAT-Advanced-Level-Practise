#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct user{
	bool show;
	vector<int> score;
	int rank,perfctsolve,totalscore,id;
	user(vector<int> score,bool show,int perfctsolve,int totalscore):score(score),show(show),totalscore(totalscore),perfctsolve(perfctsolve){
	}
};
vector<user> users;
vector<int> problems;

bool cmpt(const user &A,const user &B)
{
	return A.totalscore>B.totalscore;
}
bool cmp(const user &A,const user &B)
{
	if(A.rank==B.rank)
	{
		if(A.perfctsolve==B.perfctsolve)
		return A.id<B.id;
		else return A.perfctsolve>B.perfctsolve;
	}else return A.rank<B.rank;
}
int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	problems.resize(k+1);
	users.assign(n+1,user(vector<int>(k+1,-1),false,0,0));
	for(int i=1;i<=k;i++)
	scanf("%d",&problems[i]);
	int tmp1,tmp2,tmp3,tmp4;
	while(m--)
	{
		scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
		if(tmp3!=-1)
		users[tmp1].show=true;
		else {
			if(users[tmp1].score[tmp2]==-1)
			users[tmp1].score[tmp2]=0;
			continue;	
		}
		
		if(users[tmp1].score[tmp2]==-1)
		users[tmp1].score[tmp2]=0;
		tmp4=tmp3-users[tmp1].score[tmp2];
		if(tmp4>0)
		{
		users[tmp1].score[tmp2]=tmp3;
		if(tmp3==problems[tmp2])
		users[tmp1].perfctsolve++;
		users[tmp1].totalscore+=tmp4;
		}
		
		users[tmp1].id=tmp1;
	}
	sort(users.begin()+1,users.end(),cmpt);
	int rank=1,sum=1,t=1;
	users[1].rank=rank;
	for(int i=2;i<users.size();i++)
	{
		if(!users[i].show)
		{
			users[i].rank=20010;
			t++;
			continue;
		}
		if(users[i].totalscore==users[i-t].totalscore)
		{
			users[i].rank=rank;
			sum++;
			
		}else{
			rank+=sum;
			users[i].rank=rank;
			sum=1;
		}
		t=1;
		
	}
	sort(users.begin()+1,users.end(),cmp);
	for(int i=1;i<n+1;i++)
	{
		if(!users[i].show)continue;
		printf("%d %05d %d",users[i].rank,users[i].id,users[i].totalscore);
		for(int j=1;j<k+1;j++)
		if(users[i].score[j]==-1)
		printf(" -");
		else printf(" %d",users[i].score[j]);
		printf("\n");
	}
	
}
