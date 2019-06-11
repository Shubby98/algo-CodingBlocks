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
    if(root->data >= data)
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

void Display(node * root)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left)
        cout<<root->left->data;
    else
        cout<<"END";
    cout<<" => "<<root->data<<" <= ";
    if(root->right)
        cout<<root->right->data;
    else
        cout<<"END";
    cout<<endl;
    Display(root->left);
    Display(root->right);
    return;
}

int main()
{
        node * root = NULL;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int num;
            cin>>num;
            ADDelement(root,num);
            ADDelement(root,num);
        }
        Display(root);
        return 0;
}
