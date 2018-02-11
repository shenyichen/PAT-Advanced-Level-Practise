#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<vector<int> >stu2cou;
int name2int(char* name)
{
	int id=0;
	id+=(name[0]-'A')*26*26*10;
	id+=(name[1]-'A')*26*10;
	id+=(name[2]-'A')*10;
	id+=(name[3]-'0');
	return id;
}
int main()
{
	int n,k,id;
	stu2cou.resize(180000);
//	freopen("E:\\cs2018\\PAT\\testcase\\1039.txt","r",stdin);
	cin>>n>>k;
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		char tem[5];
		while(b--)
		{
			scanf("%s",tem);
			id=name2int(tem);
			stu2cou[id].push_back(a);
		}
		
	}
	char tem[5];
	while(n--)
	{
		scanf("%s",tem);
		printf("%s",tem);
		id=name2int(tem);
		int size=stu2cou[id].size();
		if(size!=0)
		{
			printf(" %d",size);

			sort(stu2cou[id].begin(),stu2cou[id].end());
			for(int i=0;i<size;i++)

			printf(" %d",stu2cou[id][i]);

		
		}else printf(" 0");
		printf("\n");

	
	}
}
