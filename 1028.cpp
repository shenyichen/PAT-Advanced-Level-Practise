#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m,c;
struct sinfo{
	int id,grade;
	string name;
	sinfo(int id,int grade,string name):id(id),grade(grade),name(name){
	}
};
vector<sinfo> students;
bool cmpi(const sinfo &A,const sinfo &B)
{
	return A.id<B.id;
}

bool cmpn(const sinfo &A,const sinfo &B)
{
	if(A.name==B.name)
	return A.id<B.id;
	return A.name<B.name;
}
bool cmpg(const sinfo &A,const sinfo &B)
{
	if(A.grade==B.grade)
	return A.id<B.id;
	return A.grade<B.grade;
}
int main()
{
	cin>>m>>c;
	
	while(m--)
	{
		int grade,id;
		string name;
		name.resize(21);
		scanf("%d %s %d",&id,&name[0],&grade);
		students.push_back(sinfo(id,grade,name));
	}
	if(c==1) sort(students.begin(),students.end(),cmpi);
	if(c==2) sort(students.begin(),students.end(),cmpn);
	if(c==3) sort(students.begin(),students.end(),cmpg);
	for(int i;i<students.size();i++)
	{
		printf("%06d %s %d\n",students[i].id,students[i].name.c_str(),students[i].grade);
	}
 } 
