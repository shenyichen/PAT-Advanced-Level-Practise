#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	node* left;
	node* right;
	int val;
	node(node* left,node* right,int val):left(left),right(right),val(val){
	}
};

int getheight(node* root)
{
	if(root==NULL) return 0;
	return max(getheight(root->left),getheight(root->right))+1;
}

node* ronateR(node* root)
{
	node* t=root->left;
	root->left=t->right;
	t->right=root;
	return t;
}

node* ronateL(node* root)
{
	node* t=root->right;
	root->right=t->left;
	t->left=root;
	return t;
}

node* ronateLR(node* root)
{
	
	root->left=ronateL(root->left);
	return ronateR(root);
}

node* ronateRL(node* root)
{
	
	root->right=ronateR(root->right);
	return ronateL(root);
}
node* avlinsert(node* root,int val)
{
	if(root==NULL)
	root=new node(NULL,NULL,val);
	else if(val<root->val)
	{
		root->left=avlinsert(root->left,val);
		if(getheight(root->left)-getheight(root->right)==2)
		root=val<root->left->val?ronateR(root):ronateLR(root);
	}
	
	else{
		root->right=avlinsert(root->right,val);
		if(getheight(root->right)-getheight(root->left)==2)
		root=val<root->right->val?ronateRL(root):ronateL(root);
	} 
	return root;

}



int main()
{
	int n,tmp;
	cin>>n;
	node* root=NULL;

	
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		root=avlinsert(root,tmp);	
	} 
	cout<<root->val;
	

}
