#include<iostream>
#include<vector>
#include<queue>
#include <sstream>
using namespace std;
struct node{
	int leftchild,rightchild;
	node(int leftchild,int rightchild):leftchild(leftchild),rightchild(rightchild){
	}
};
string level,in;
vector<node> bst;
queue<int> q;
void inorder(int root)
{
	if(root==-1) return;
	inorder(bst[root].leftchild);
	in+=root+'0';
	in+=" ";
	inorder(bst[root].rightchild);
	
}

int main()
{
	int n,root;
	char l,r;
	cin>>n;
	vector<int> ncount(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>l>>r;
		if(l=='-')
		l=-1;
		else 
		{
		ncount[l-='0']++;	
		}
		if(r=='-')
		r=-1;
		else ncount[r-='0']++;
		bst.push_back(node(r,l));
	}
		for(int i=0;i<n;i++)
	{
		if(ncount[i]==0)
		{
			root=i;
			break;
		}
	}
	

		q.push(root);
		while(!q.empty())
		{
			level+=q.front()+'0';
			level+=" ";
			if(bst[q.front()].leftchild!=-1)
			q.push(bst[q.front()].leftchild);
			
			if(bst[q.front()].rightchild!=-1)
			q.push(bst[q.front()].rightchild);
			q.pop();
		}

	
	inorder(root);
	level[level.size()-1]='\n';
	in[in.size()-1]='\0';
	cout<<level<<in;
	
} 
