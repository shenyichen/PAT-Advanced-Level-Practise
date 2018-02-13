#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct info {
	string name;
	int age,networth;
	info(string name,int age,int networth):name(name),age(age),networth(networth) {

	}
	bool operator <(const info &A)const {
		if(networth==A.networth) {
			if(age==A.age) {
				return name<A.name;
			}

			return age<A.age;
		}
		return networth>A.networth;
	}
};

vector<info> list,newlist;
vector<int> agelist(201,0);
int main() {
//	freopen("D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1055.txt","r",stdin);
	int n,k,tmpage,tmpworth;
	string tmpname;
	tmpname.resize(8);
	cin>>n>>k;
	while(n--) {
		scanf("%s %d %d",&tmpname[0],&tmpage,&tmpworth);
		newlist.push_back(info(tmpname,tmpage,tmpworth));

	}

	sort(newlist.begin(),newlist.end());
	for(int i=0;i<newlist.size();i++)
	{
		if(agelist[newlist[i].age]<100)
		list.push_back(newlist[i]);
		agelist[newlist[i].age]++;
	}
	int max,agelow,ageup,lc;
	string tmpout;
	for(int i=1; i<=k; i++) {


		
		{
			scanf("%d%d%d",&max,&agelow,&ageup);
			printf("Case #%d:\n",i);
			lc=0;
			for(int j=0;j<list.size();j++)
			{
				if(list[j].age>=agelow &&ageup>=list[j].age &&lc<max)
				{
					printf("%s %d %d\n",list[j].name.c_str(),list[j].age,list[j].networth);
					lc++;
				}
				
				
			}
			if(lc==0)
			 printf("None\n");
		}
	}
}
