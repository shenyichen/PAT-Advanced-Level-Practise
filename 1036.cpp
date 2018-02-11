#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string name,lesson;
	int grade;
	char gender;
	student(string name,char gender,string lesson,int grade):name(name),gender(gender),lesson(lesson),grade(grade)
	{
	}
};

	bool compM (const student &A,const student &B)
	{
		return A.grade<B.grade;
	}
		bool compF (const student &A,const student &B)
	{
		return A.grade>B.grade;
	}
vector<student>male,fmale;
int main(){
	
	int sum;
	cin>>sum;
	while(sum--)
	{
		string a,d;
		char b;
		int c;
		cin>>a>>b>>d>>c;
		if(b=='M')
		male.push_back(student(a,b,d,c));
		else fmale.push_back(student(a,b,d,c));
	}
	sort(male.begin(),male.end(),compM);
	sort(fmale.begin(),fmale.end(),compF);
	if(male.size()!=0 && fmale.size()!=0)
	{
		cout<<fmale[0].name<<" "<<fmale[0].lesson<<endl;
		cout<<male[0].name<<" "<<male[0].lesson<<endl;
		cout<<fmale[0].grade-male[0].grade;
	}else if(male.size()==0)
	{
	cout<<fmale[0].name<<" "<<fmale[0].lesson<<endl<<"Absent"<<endl<<"NA";

	}else cout<<"Absent"<<endl<<male[0].name<<" "<<male[0].lesson<<endl<<"NA";
	
}
