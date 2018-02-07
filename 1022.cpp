#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include<set>
using namespace std;
map<string, set<int> >	titles,years,publishers,authors,keys;
int main()
{
	freopen( "D:\\CS2018\\PAT-Advanced-Level-Practise\\testcase\\1022.txt", "r", stdin );
	int a, b;
	cin >> a;
	while ( a-- )
	{
		int	id;
		string	title, author, publisher, year;
		cin >> id;
		getchar();
		getline(cin, title);
		getline( cin, author );
		do
		{
			string temp;
			cin >> temp;
			keys[temp].insert( id );
		}
		while ( getchar() != '\n' );

		getline( cin, publisher );
		cin >> year;
		years[year].insert(id);
		titles[title].insert(id);
		authors[author].insert(id);
		publishers[publisher].insert(id);
		
	}
	cin >> b;
	getchar();
	map<string, set<int> >:: iterator mit;
	set<int> :: iterator sit;
	while ( b-- )
	{
		string	q;
		bool	flag = false;
		getline( cin, q );
		cout << q << endl;
		int p = q[0] - '0';
		if ( p == 1 )
		{
			mit=titles.find(q.substr( 3 ));
			if(mit!=titles.end())
			{
				for(sit=(*mit).second.begin();sit!=(*mit).second.end();sit++)
				{
					printf("%7d\n",*sit);
					
				}
				flag =true;
				
			}
		}
		if ( p == 2 )
		{
			mit=authors.find(q.substr( 3 ));
			if(mit!=authors.end())
			{
				for(sit=(*mit).second.begin();sit!=(*mit).second.end();sit++)
				{
					printf("%7d\n",*sit);
					
				}
				flag =true;
				
			}
		}

		if ( p == 4 )
		{
			mit=publishers.find(q.substr( 3 ));
			if(mit!=publishers.end())
			{
				for(sit=(*mit).second.begin();sit!=(*mit).second.end();sit++)
				{
					printf("%7d\n",*sit);
					
				}
				flag =true;
				
			}
		}

		if ( p == 5 )
		{
			mit=years.find(q.substr( 3 ));
			if(mit!=years.end())
			{
				for(sit=(*mit).second.begin();sit!=(*mit).second.end();sit++)
				{
					printf("%7d\n",*sit);
					
				}
				flag =true;
				
			}
		}
		if ( p == 3 )
		{	
			mit=keys.find(q.substr( 3 ));
			if(mit!=keys.end())
			{
				for(sit=(*mit).second.begin();sit!=(*mit).second.end();sit++)
				{
					printf("%7d\n",*sit);
					
				}
				flag =true;
				
			}
		}
		if ( flag == false )
			cout << "Not Found" << endl;
	}
	return 0;
}



