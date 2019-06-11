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
		string left;	
		cin>>left;
		if(left == "true")
		{
			cin>>data;
			node * temp =  new node(data);
			top->left = temp;
			q.push(temp);
		}
	//	cout<<"enter data of right child of "<<top->data<<endl;
		string right;
		cin>>right;
		if(right == "true")
		{
			cin>>data;
			node * temp =  new node(data);
			top->right = temp;
			q.push(temp);
		}
		q.pop();
	}	
}

void root2leaf(node * root , int k,int &sum)
{
	if(root==NULL)
	{
		return ;
	}
	if(sum == k)
	{
		return ;
	}
	cout<<root->data<<" ";
	sum += root->data;
	root2leaf(root->left,k,sum);
	root2leaf(root->right,k,sum);
	return ;
}


int main()
{
	node * root;
	build(root);
	int k;
	cin>>k;
	int sum = 0;
	root2leaf(root , k,sum);
}




