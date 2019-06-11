#include<iostream>
#include<vector>

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

int find(vector<int>v,int s,int e,int k)
{
    for(int i=s;i<=e;i++){
        if(v[i]==k){
            return i;
        }
    }
    return -1;
}

node * TREEfromPOSTandIN(vector <int> post,int pstart,int pend,vector <int> in,int instart,int inend)
{
    if(instart>inend)
    {
        return NULL;
    }



    int rootdata = post[pend];
    node* root = new node(rootdata);
    if(instart == inend)
        return root;
    int rootindex = find(in,instart,inend,rootdata);
    int l = rootindex - instart;
    int r = inend - rootindex;
    root->left = TREEfromPOSTandIN(post,pstart,pstart+l-1,in,instart,rootindex-1);
    root->right = TREEfromPOSTandIN(post,pstart+l+1-1,pend-1,in,rootindex+1,inend);
    return root;
}


void inorder(node * root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}


void postorder(node * root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    int n;
    cin>>n;
    vector <int> post;
    for(int i = 0;i<n;i++)
    {
        int num;
        cin>>num;
        post.push_back(num);
    }
    int m;
    cin>>m;
    vector <int> in;
    for(int i = 0;i<m;i++)
    {
        int num;
        cin>>num;
        in.push_back(num);
    }

    node * root = TREEfromPOSTandIN(post,0,n-1,in,0,m-1);
    Display(root);
    return 0;
}
