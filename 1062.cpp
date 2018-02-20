#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info{
	int id,virtue,talent;
	info(int id,int virtue,int talent):id(id),virtue(virtue),talent(talent){
	}
	bool operator <(const info &A)const{
		int a=virtue+talent,b=A.talent+A.virtue;
		if(a==b)
		{
			if(virtue==A.virtue)
			return id<A.id;
			else return virtue>A.virtue;
		}
		
		else return a>b;
	}
	
};
vector<info> sage,nobleman,fool,small;
int main()
{
	int a,b,c;
	int id,virtue,talent;
	cin>>a>>b>>c;
	while(a--)
	{
		scanf("%d %d %d",&id,&virtue,&talent);
		if(virtue>=b && talent>=b)
		{
			if(virtue>=c)
			{
				if(talent>=c)
				sage.push_back(info(id,virtue,talent));
				else nobleman.push_back(info(id,virtue,talent));
			
				
			}else if(virtue>=talent)
			fool.push_back(info(id,virtue,talent));
			else small.push_back(info(id,virtue,talent));
		}
	}
	
	int sum=sage.size()+nobleman.size()+fool.size()+small.size();
	printf("%d\n",sum);
	sort(sage.begin(),sage.end());
	sort(nobleman.begin(),nobleman.end());
	sort(fool.begin(),fool.end());
	sort(small.begin(),small.end());
	for(int i=0;i<sage.size();i++)
	printf("%d %d %d\n",sage[i].id,sage[i].virtue,sage[i].talent); 
	for(int i=0;i<nobleman.size();i++)
	printf("%d %d %d\n",nobleman[i].id,nobleman[i].virtue,nobleman[i].talent); 
	for(int i=0;i<fool.size();i++)
	printf("%d %d %d\n",fool[i].id,fool[i].virtue,fool[i].talent);
		for(int i=0;i<small.size();i++)
	printf("%d %d %d\n",small[i].id,small[i].virtue,small[i].talent);
}
