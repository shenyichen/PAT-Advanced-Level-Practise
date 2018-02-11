#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct cardinfo{
	int order;
	string card;
	cardinfo(int order,string card):order(order),card(card){
		
	}
	bool operator <(const cardinfo &A)const
	{
		return order<A.order;
	}
};
vector<cardinfo> cards;
vector<int> orders;
int main()
{
	for(int i=0;i<9;i++)
	{
		string tmp="S";
		tmp+=i+'1';
		cards.push_back(cardinfo(i,tmp));
	}
	for(int i=0;i<4;i++)
	{
		string tmp="S1";
		tmp+=i+'0';
		cards.push_back(cardinfo(i+9,tmp));
	}
		for(int i=0;i<9;i++)
	{
		string tmp="H";
		tmp+=i+'1';
		cards.push_back(cardinfo(i+13,tmp));
	}
	for(int i=0;i<4;i++)
	{
		string tmp="H1";
		tmp+=i+'0';
		cards.push_back(cardinfo(i+22,tmp));
	}
		for(int i=0;i<9;i++)
	{
		string tmp="C";
		tmp+=i+'1';
		cards.push_back(cardinfo(i+26,tmp));
	}
	for(int i=0;i<4;i++)
	{
		string tmp="C1";
		tmp+=i+'0';
		cards.push_back(cardinfo(i+35,tmp));
	}
		for(int i=0;i<9;i++)
	{
		string tmp="D";
		tmp+=i+'1';
		cards.push_back(cardinfo(i+39,tmp));
	}
	for(int i=0;i<4;i++)
	{
		string tmp="D1";
		tmp+=i+'0';
		cards.push_back(cardinfo(i+43,tmp));
	}
	for(int i=0;i<2;i++)
	{
		string tmp="J";
		tmp+=i+'1';
		cards.push_back(cardinfo(i+52,tmp));
	}

	int a;
	cin>>a;
	for(int i=0;i<54;i++)
	{
		int b;
		cin>>b;
		orders.push_back(b);
	}
	while(a--)
	{
		for(int i=0;i<54;i++)
		{
			cards[i].order=orders[i]-1;
		}
		sort(cards.begin(),cards.end());
		
	}
		cout<<cards[0].card;
		for(int i=1;i<54;i++)
		{
			cout<<" "<<cards[i].card;
		}
 } 
