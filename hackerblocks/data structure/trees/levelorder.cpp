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

node * marker()
{
	return new node(-1);

}

void levelorder(node * root)
{
    queue<node *> q;
    q.push(root);
    q.push(marker());
    while(!q.empty())
    {
        node * top = q.front();
        if(top->data==-1)
        {
            cout<<endl;
            q.pop();
            q.push(marker());
            top = q.front();
        }
        if(top->data!=-1)
        cout<<top->data<<" ";

        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);

        q.pop();
    }
    return;
}

int main()
{
    node * root =NULL;
    int data;
    cin>>data;
    root = new node(data);
    build(root);
    levelorder(root);

}


