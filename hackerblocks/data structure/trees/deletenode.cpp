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

node * deletenode(node * root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data > data)
    {
        root->left = deletenode(root->left,data);
        return root;
    }

    else if(root->data == data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL)
        {
            node * temp = root->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL)
        {
            node * temp = root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL)
        {
            node * change = root->left;

            while(change->right!=NULL)
            {
                change = change->right;
            }

            root->data = change->data;
            root->left = deletenode(root->left,change->data);
            return root;

        }
    }

    else
    {
        root->left = deletenode(root->right,data);
        return root;
    }

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

        int m;
        cin>>m;
        while(m--)
        {
            int num;
            cin>>num;
            deletenode(root,num);
        }
        preorder(root);
    }
}
