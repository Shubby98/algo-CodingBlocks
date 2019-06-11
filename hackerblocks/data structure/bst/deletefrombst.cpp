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

struct btree
{
    node * root;
    btree()
    {
        root = NULL;
    }

    void insert(int data)
    {
        if(root==NULL)
        {
            root = new node(data);
        }

        if(root->data>)
    }

}

int main()
{
    int t;
    cin>>t;
    wjile(t--)
    {
        int n;
        cin>>n;
        int arr1[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
            insert(arr1[i]);
        }

        int m;
        cin>>m;
        int arr2[m];
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }

    }
}
