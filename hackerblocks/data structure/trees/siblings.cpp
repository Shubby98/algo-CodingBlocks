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

void siblings(node * root,bool flag)
{
    if(root==NULL)
    {
        return;
    }
    bool left=false ,right=false;
    if(root->left==NULL)
        left = true;
    if(root->right==NULL)
        right = true;

    if(flag)
    {
        cout<<root->data<<" ";
    }
    if(left || right)
    {
        flag = true;
    }
    siblings(root->left,flag);
    siblings(root->right,flag);
    return;

}

int main()
{

  node * root;
  int data;
  cin>>data;
  root =  new node(data);
  build(root);
    siblings(root,false);

}
