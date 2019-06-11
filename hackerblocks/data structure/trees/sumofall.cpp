#include<iostream>
#include<queue>
#include<limits.h>

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
    if(root==NULL)
    {
        return;
    }
    string s;
    cin>>s;
    if(s == "true")
    {
        int data;
        cin>>data;
        root->left = new node(data);
        build(root->left);
    }
    else
        return;
    cin>>s;
    if(s == "true")
    {
        int data;
        cin>>data;
        root->right = new node(data);
        build(root->right);
    }
    else
        return;

    return;

}

int sum(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    int s = 0;
    s += sum(root->left);
    s += sum(root->right);
    s += root->data;
    return s;
}

void preorder(node * root)
{
    if(root== NULL)
    {
        cout<<"NULL ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int main()
{

  node * root;
  int data;
  cin>>data;
  root =  new node(data);
  build(root);
  preorder(root);
  //cout<<endl<<sum(root);

}
