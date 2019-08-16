#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node * next;
	node(int data)
	{
		this->data =  data;
		next =  NULL;
	}
};

void create(node * &head,int n)
{
	if(n==0)
	{
		head = NULL;
		return;
	}
	int data;
	cin>>data;
	head = new node(data);
	node * trav = head;
	n--;
	while(n--)
	{
		//cout<<"***"<<endl;
		int data;
		cin>>data;
		trav->next = new node(data);
		trav = trav->next;
	}
}

void print(node* &head)
{
	node * trav = head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav =  trav->next;
	}
	cout<<endl;
}

node* Kappend(node* &head ,int k)
{

    if(head==NULL || head->next == NULL)
    {
        return head;
    }
    node * prev = head;
    while(--k)
    {
        prev = prev->next;
        //cout<<prev->data<<" ";
    }

    node * first = prev->next;
    node* last = first;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    last->next = head;
    prev->next = NULL;
    //cout<<first->data<<endl;

    //print(first);
    return first;
}


int main()
{

		int n;
		cin>>n;
		node * head;
		create(head,n);
		int k;
		cin>>k;
		if(k>=n)
		{
            k = k%n;
		}
		if(k!=0)
		head = Kappend(head,n-k);

		print(head);

}




