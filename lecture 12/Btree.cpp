#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
	
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

void levelorder(node * root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node * top = q.front();
		if(top->left)
		{
			q.push(top->left);
		}
		if(top->right)
		{
			q.push(top->right);
		}
		cout<<top->data<<" ";
		q.pop();
	}
}

int count(node * root)
{
	if( root == NULL)
	{
		return 0;
	}
	
	int left  =  count(root->left);
	int right =  count(root->right);
	return left + right + 1;
}

int maximum(node * root)
{
	if(root ==NULL)
	{
		return INT_MIN;	
	}	
	int left = maximum(root->left);
	int right = maximum(root->right);
	int max =  root->data;
	if(max<left)
	{
		max =  left;
	}
	if(max<right)
	{
		max =  right;
	}
	return max;
}

int greaterthanX(node * root, int x)
{
	if(root == NULL)
	{
		return 0;
	}
	int left = greaterthanX(root->left,x);
	int right = greaterthanX(root->right,x);
	int count = 0;
	if(root->data>x)
	{
		count = 1;
	}
	return left + right+ count;
}

int allsum(node * root)
{
	if(root == NULL)
	{
		return 0;
	}
	int sum = root->data;
	if(root->left != NULL)
	{
		sum += root->left->data;
	}
	if(root->right != NULL)
	{
		sum += root->right->data;
	}
	return sum;
}

node * greatestsum(node * root)
{
	if(root == NULL)
	{
		return NULL;
	}
	node * lnode =  greatestsum(root->left);
	node * rnode =  greatestsum(root->right); 
	 
	int curr = 0;             
	curr =  allsum(root);
	if(curr<allsum(lnode))
	{
		return lnode;
	}
	if(curr<allsum(rnode))
	{
		return rnode;
	}
	
	return root;
}
// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 
int main()
{
	node * root ;
	create(root);
	cout<<"postorder "<<endl;
	postorder(root);
	cout<<"\nInorder "<<endl;
	inorder(root);
	cout<<"\nPreorder "<<endl;
	preorder(root);
	cout<<"\nLevelorder "<<endl;
	levelorder(root);
	cout<<"\nCount "<<endl;
	cout<<count(root)<<endl;
	cout<<"\nGreatest Node "<<endl;
	cout<<maximum(root)<<endl;
	cout<<"\nGreatest than X "<<endl;
	cout<<greaterthanX(root,7)<<endl;
	node * great =  greatestsum( root);
	cout<<"\ngreatest sum node = "<<great->data<<endl;
	
	
}
