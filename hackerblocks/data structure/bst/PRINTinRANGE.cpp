#include<iostream>

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

void ADDelement(node * &root, int data)
{
    node * temp= new node(data);
    if(root == NULL)
    {
        root = temp;
        return;
    }
    if(root->data > data)
    {
        ADDelement(root->left,data);
    }
    else
    {
        ADDelement(root->right,data);
    }
    return ;
}

void preorder(node * root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void printinrange(node * root,int k1,int k2)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data > k2)
        printinrange(root->left,k1,k2);
    if(root->data < k1)
        printinrange(root->right,k1,k2);
    if(root->data >= k1 && root->data <= k2)
    {
        printinrange(root->left,k1,k2);
        cout<<root->data<<" ";
        printinrange(root->right,k1,k2);
    }
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        node * root = NULL;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int num;
            cin>>num;
            ADDelement(root,num);
        }
        int k1,k2;
        cin>>k1>>k2;
        cout<<"# Preorder : ";
        preorder(root);
        cout<<endl<<"# Nodes within range are : ";
        printinrange(root,k1,k2);

    }
}
