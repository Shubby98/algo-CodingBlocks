#include<iostream>
#include<queue>
#include<limits.h>

using namespace std;

int arr[100][1000];
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



void levelorder(node * root,vector <vector<int> > v)
{
    queue<node *> q;
    q.push(root);
    q.push(marker());
    int i = 0;
    while(!q.empty())
    {
        node * top = q.front();
        if(top->data==-1)
        {
            v[i].push_back(top->data);
            i++;
            q.pop();
            q.push(marker());
            top = q.front();
        }
        if(top->data!=-1)
        {
            v[i].push_back(top->data);
        }
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
        //arr[i][j] =  top->data;
        q.pop();
    }
    return ;
}

int main()
{
    vector <vector<int> > v;
    node * root =NULL;
    int data;
    cin>>data;
    root = new node(data);
    build(root);
    levelorder(root,v);

    for(int i = 0; i<10;i++)
    {
        for(int j = 0;j<10;j++)
        {
            cout<<v[i][j]<<"   ";
        }
        cout<<endl;
    }
/*
    cout<<"[[";
    for(int i =0;i<v.size();i++ )
    {
        if(i!=0)
            cout<<"[";
        int j = 0;
        while(v[i][j]!=-1)
        {
            if(j!=0)
            cout<<",";

            cout<<arr[i][j];
            j++;
        }
        cout<<"] ";
    }
    cout<<"]";
*/
}


