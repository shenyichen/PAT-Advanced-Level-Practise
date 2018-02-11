#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> num; 
bool cmp(const string &A,const string &B)
{
	return A+B<B+A;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string tmp;
		cin>>tmp;
		num.push_back(tmp);
	 }
	 sort(num.begin(),num.end(),cmp);
	 string result;
	 
	 	 for(int i=0;i<num.size();i++)
		result+=num[i];
	int i=0;
	for(;i<result.size()-1;i++)
	if(result[i]!='0') break;
	result=result.substr(i);
	cout<<result;


}
