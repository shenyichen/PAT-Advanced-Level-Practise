#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,int> wcount;
vector<string> result;
int main(){
	char tmp,tmp1;
	string verb;
	while(tmp!='\n')
	{	
		tmp=getchar();			
		tmp1=tmp-'a';
		if(tmp1>=0 && tmp1<26)
		verb+=tmp;
		else{
			
			
		tmp1=tmp-'A';			
		if(tmp1>=0 && tmp1<26)
		verb+=tmp1+'a';
		else{
			
		tmp1=tmp-'0';
		if(tmp1>=0 && tmp1<10)
		verb+=tmp;
		else if(verb.length()>0)
		{
			if(wcount.find(verb)==wcount.end())
			wcount[verb]=1;
			else wcount[verb]++;
			verb.clear();
		}

		}


	
			
		}



		
	}
	map<string,int>::iterator it;
	int maxc=0;
	for(it=wcount.begin();it!=wcount.end();it++)
	{
		if(it->second>maxc)
		{
			result.clear();
			result.push_back(it->first);
			maxc=it->second;
		}else if(it->second==maxc)
		result.push_back(it->first);
	}
	sort(result.begin(),result.end());
	if(result.size()>0)
	cout<<result[0]<<" "<<wcount[result[0]];
	
}
