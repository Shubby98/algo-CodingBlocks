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

void arroflevel(node * root,int arr[][1000])
{
    queue <node *> q;
    q.push(root);
    q.push(marker());
    int i = 0,j = 0;
    while(!q.empty())
    {
        node * top = q.front();
        if(top->data==-1)
        {
            q.pop();
            arr[i][j] = top->data;
            i = i+1;
            j = 0;
            q.push(marker());
            top = q.front();
        }
        if(top->data!=-1)
        {
            arr[i][j] = top->data;
            j++;
        }

        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);

        q.pop();
    }
    arr[i][j] = -1;
    return ;

}
int main()
{
    node * root;
    int data;
    cin>>data;
    root = new node(data);
    build(root);
    int arr[100][1000];
    arroflevel(root,arr);
    cout<<"[";
    for(int i=0; arr[i][0]!=-1 ;i++)
    {

        cout<<"[";
        for(int j = 0;arr[i][j]!=-1;j++)
        {
            cout<<arr[i][j];
            if(arr[i][j+1]!=-1)
                cout<<", ";
        }
        cout<<"]";
        if(arr[i+1][0]!=-1)
            cout<<", ";

    }
    cout<<"]";

/*
    int i = 0,j=0;
    while(arr[i][0]!=-1)
    {
        while(arr[i][j]!=-1)
        {
            cout<<arr[i][j]<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
*/
}
