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

bool isIdentical(node * root1,node * root2)
{
	if(root1==NULL && root2 == NULL )
	{
		return true;
	}
	else if(root1!=NULL && root2!=NULL )
	{
        bool left,right;
        left = isIdentical(root1->left,root2->left);
        right = isIdentical(root1->right,root2->right);
        if(left==true && right==true)
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}


int main()
{
	node * root1=NULL;
    int data;
    cin>>data;
    root1 =  new node(data);
    build(root1);
    //cout<<"root1 khatam"<<endl;

	node * root2=NULL;
    cin>>data;
    root2 =  new node(data);
    build(root2);

    if(isIdentical(root1,root2))
	cout<<"true"<<endl;
	else
	cout<<"false"<<endl;
}
