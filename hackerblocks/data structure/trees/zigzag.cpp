#include<iostream>
#include<stack>
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

void zigzag(node * root)
{
    stack <node * > rightstack,leftstack;
    leftstack.push(root);
    while(!leftstack.empty() || !rightstack.empty())
    {
        //cout<<"stack khaali nhi hai"<<endl;
        while(leftstack.empty()==false)
        {
            node * top = leftstack.top();
            leftstack.pop();
            cout<<top->data<<" ";
            if(top->left!=NULL)
                rightstack.push(top->left);
            if(top->right!=NULL)
                rightstack.push(top->right);
        }

        while(rightstack.empty()==false)
        {
            node * top = rightstack.top();
            rightstack.pop();
            cout<<top->data<<" ";
            if(top->right!=NULL)
                leftstack.push(top->right);
            if(top->left!=NULL)
                leftstack.push(top->left);

        }
    }

}

int main()
{
    node * root =NULL;
    int data;
    cin>>data;
    root = new node(data);
    build(root);
    //cout<<" build hogya"<<endl;
    zigzag(root);
    return 0;
}


