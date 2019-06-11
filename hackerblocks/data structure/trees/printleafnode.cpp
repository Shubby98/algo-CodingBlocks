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
		this->data = data;
		left = right = NULL;
	}
};

void build(node * &root)
{
	//cout<<"enter the data and -1 to exit"<<endl;
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
	//	cout<<"enter data of left child of "<<top->data<<endl;
		cin>>data;
		if(data!=-1)
		{
			node * temp =  new node(data);
			top->left = temp;
			q.push(temp);
		}
	//	cout<<"enter data of right child of "<<top->data<<endl;
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

void leafnode(node * root)
{
	if(root->left== NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
	}
	leafnode(root->left);
	leafnode(root->right);
	return;
}

int main()
{
	node * root ;
	build(root);
	leafnode(root);
}
