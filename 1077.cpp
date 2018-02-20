#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,min=257;
	string tmp;
	cin>>n;
	getchar();
	vector<string> strings;
	while(n--)
	{
		getline(cin,tmp);
		if(min>tmp.size())
		min=tmp.size();
		strings.push_back(tmp);
			
		
	}
	tmp="";
	for(int i=1;i<=min;i++)
	{
		for(int j=1;j<strings.size();j++)
		{
			if(strings[j][strings[j].length()-i]!=strings[j-1][strings[j-1].length()-i])
			{
				if(tmp.size()!=0)
				{
					reverse(tmp.begin(),tmp.end());
					cout<<tmp;
				}
				
				else cout<<"nai";
				return 0;
			}

		}
		tmp+=strings[0][strings[0].length()-i];
	}
	
					if(tmp.size()!=0)
					{
						reverse(tmp.begin(),tmp.end());
						cout<<tmp;
					}
				
				else cout<<"nai";
				return 0;
} 
