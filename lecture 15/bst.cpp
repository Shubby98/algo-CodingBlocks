#include<iostream>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node* parent ;
	
	node(int data = 0)
	{
		this->data =  data;
		left = right = parent = NULL;
	}
	
};

void inorder(node * root)
{
	if(root == NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	inorder(root->left);

	inorder(root->right);
	return;
}

node * bstfromsortedarr(int arr[],int start ,int end)
{
	if(end<start)
	{
		return NULL;
	}
	
	int mid = (start + end)/2;
	node * root = new node(arr[mid]);
	
	root->left = bstfromsortedarr(arr,start,mid-1);
	root->right = bstfromsortedarr(arr,mid+1 ,end);
	
	return root;
}

bool balanced(node * root)
{
	
}

int main()
{
	int n;
	cout<<"enter no of element"<<endl;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n ;i++)
	{
		cin>>arr[i];
	}
	node * root = bstfromsortedarr(arr,0,n-1);
	inorder(root);
	return 0;
	
}


