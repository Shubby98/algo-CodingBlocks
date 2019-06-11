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
    cin>>s;
    if(s == "true")
    {
        int data;
        cin>>data;
        root->right = new node(data);
        build(root->right);
    }
    return;
}

bool isleaf(node * root)
{

    if(root->left==NULL && root->right==NULL )
    {
        return true;
    }
    else
    return false;
}

void removeleaf(node* root)
{
    delete root;
    return;
}

void removeleaves(node * root)
{
    if(root==NULL)
    {
        return ;
    }

    if(root->left==NULL)
    {
        cout<<"END";
    }
    else
    {
        if(isleaf(root->left))
        {
            removeleaf(root->left);
            root->left = NULL;
            cout<<"END";
        }
        else
        {
            cout<<root->left->data;
        }
    }

    cout<<" => "<<root->data<<" <= ";

    if(root->right==NULL)
    {
        cout<<"END"<<endl;
    }
    else
    {
        if(isleaf(root->right))
        {
            removeleaf(root->right);
            root->right = NULL;
            cout<<"END"<<endl;
        }
        else
        {
            cout<<root->right->data<<endl;
        }
    }


    removeleaves(root->left);
    removeleaves(root->right);


    return;

}

int main()
{

  node * root=NULL;
  int data;
  cin>>data;
  root = new node(data);
  build(root);
  removeleaves(root);

}
