#include<iostream>
#include<cstring>
using namespace std;
string numInenglish[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char printNum[101];
int main()
{
	char num[101];
	cin>>num;
	int sum=0;
	int len=strlen(num);
	for(int i=0;i<len;i++) sum+=num[i]-'0';
	if(sum==0)
	{
		cout<<"zero";
		return 0;
	}
	int n=0;
	while(sum>=10)
	{
		printNum[n]=sum%10;
		sum/=10;
		n++;
	}
	printNum[n]=sum;
	cout<<numInenglish[printNum[n]];
	while(n--)
	{
		cout<<" "<<numInenglish[printNum[n]];
	}
}
