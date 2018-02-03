#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char student1[16],student2[16];
	char come[9]="23:59:59";
	char go[9]="00:00:00";
	char scome[9];
	char sgo[9];
	char student[16];
	int k;
	cin>>k;
	while(k--)
	{
		cin>>student;
		cin>>scome;
		cin>>sgo;
		if(strcmp(scome,come)<0)
		{
			 strcpy(student1,student);
			 strcpy(come,scome);
		}
		if(strcmp(sgo,go)>0) 
		{
			 strcpy(student2,student);
			 strcpy(go,sgo);
			
		}
		
	
	}
		cout<<student1<<" "<<student2;
}
