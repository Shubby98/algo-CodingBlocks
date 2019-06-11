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

node * TREEfromPREandIN(vector<int>pre,int pstart,int pend,vector<int>in,int istart,int iend){
        if(pstart>pend){
            return NULL;
        }
        int rootData = pre[pstart];
        node * root = new node(rootData);
        int index = find(in,istart,iend,rootData);
        int l = index - istart;
        int r = iend - index;
        root->left = TREEfromPREandIN(pre,pstart+1,pstart+l,in,istart,index-1);
        root->right = TREEfromPREandIN(pre,pstart+l+1,pend,in,index+1,iend);
        return root;
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
    vector <int> pre;
    for(int i = 0;i<n;i++)
    {
        int num;
        cin>>num;
        pre.push_back(num);
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

    node * root = TREEfromPREandIN(pre,0,n-1,in,0,m-1);
    Display(root);
    return 0;
}
