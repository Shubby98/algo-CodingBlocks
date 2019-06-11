#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
	int depth;
	
	node(int data)
	{
		this->data =  data;
		left = NULL;
		right =  NULL;
	}
};

void create(node* &root)
{
	cout<<"enter the data and -1 to exit"<<endl;
	int data;
	cin>>data;
	
	if(data!=-1)
	{
		root = new node(data);
		//root->data =  data;
	}
	else{
		return;
	}
	
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node * top =  q.front();
		cout<<"enter data of left child of "<<top->data<<endl;
		cin>>data;
		if(data!=-1)
		{
			node * temp =  new node(data);
			top->left = temp;
			q.push(temp);
		}
		cout<<"enter data of right child of "<<top->data<<endl;
		cin>>data;
		if(data!=-1)
		{
			node * temp =  new node(data);
			top->right = temp;
			q.push(temp);
		}
		q.pop();
	}
	
}

void postorder(node * root)
{	
	if(root == NULL)
	{
		return ;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	return;

}

void preorder(node * root)
{	
	if(root == NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
	return;

}


void inorder(node * root)
{	
	if(root == NULL)
	{
		return ;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	return;

}

int degree(node * root)
{
	if(root == NULL)
	{
		return 0;
	}
	return (bool)root->left + (bool)root->right;
}

int height(node * root)
{
	if(root ==  NULL)
	{
		return 0;
	}
	int left =  height(root->left);
	int right = height(root->left);
	if(left>right)
	{
		return left+1;
	}
	else
	{
		return right+1;
	}
	
	//return max(left,right)+1;
	
}


void populate(node * root,int d)
{
	if(root == NULL)
	{
		return;
	}
	root->depth =  d;
	populate(root->left,d+1);
	populate(root->right,d+1);
}

void atdepthK(node * root,int k)
{
	if(root == NULL)
	{
		return;
	}
	if(root->depth == k)
	{
		cout<<root->data<<" ";
	}
	atdepthK(root->left,k);
	atdepthK(root->right,k);
	return;
}

node * marker()
{
	return new node(-1);
	
}

void levelwise(node *root)
{
	queue<node *> q;
	q.push(root);
	q.push(marker());
	while(!q.empty())
	{
		node * temp =  q.front();
		if(temp->data == -1)
		{
			cout<<endl;
			q.pop();
			q.push(marker());
			temp =  q.front();
		}
		
		cout<<(height(temp))<<" ";
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
		q.pop();
	}
}

int diameter(node  * root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int left =  height(root->left) + 1;
	int right =  height(root->left) + 1;
	int dia =  left + right + 1;
	
	int ldia = diameter(root->left);
	int rdia =  diameter(root->right);
	int ma =  max(ldia,rdia) ;
	
	return max(ma,dia);
}

bool findnode(node * root,int n)
{
	if(root == NULL)
	{
		return false;
	}
	bool flag = false;
	flag = findnode(root->left,n);
	flag = findnode(root->right,n);
	if(root->data == n)
	{
		return true;
	}
	return flag;
}

// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 
int main()
{
	node * root;
	create(root);
	cout<<"degree of root = "<<degree(root)<<endl;
	cout<<"height of root = "<<height(root)<<endl;
	populate(root,0);
	cout<<"at depth K of root = ";
	atdepthK(root,2);
	cout<<endl;
	//levelwise(root);
	cout<<"diameter = "<<diameter(root)<<endl;
	
	cout<<findnode(root,55);
}










