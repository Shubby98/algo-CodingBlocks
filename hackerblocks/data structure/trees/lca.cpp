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

void lca(node * root,int x,int y,bool &xflag,bool &yflag,int &mini)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->data==x)
    {
        xflag = true;
    }
    if(root->data==y)
    {
        yflag = true;
    }
    if(xflag == false || yflag == false)
    {
        lca(root->left,x,y,xflag,yflag,mini);
        lca(root->right,x,y,xflag,yflag,mini);
        if(mini>root->data)
        {
            mini=root->data;
        }
        return;
    }

    else
    {
        if(mini>root->data)
        {
            mini=root->data;
        }
        return ;
    }
}


int main()
{
	node * root1=NULL;
    int data;
    cin>>data;
    root1 =  new node(data);
    build(root1);

	int x,y,mini = INT_MAX;
	bool xflag,yflag;
	cin>>x>>y;
    lca(root1,x,y,xflag,yflag,mini);
    cout<<mini<<endl;

}
