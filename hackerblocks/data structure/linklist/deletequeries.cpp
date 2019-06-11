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

void del(node ** head,int index)
{
	int count = 1;
	if(index == 0)
	{
		node* temp = (*head);
		*head = temp->next;
		delete temp;
		return;
		
	}
	node * trav = *head;
	while(trav!=NULL)
	{
		if(count==index)
		{
			node * temp = (trav)->next;
			(trav)->next =  temp->next;
			delete temp;
			return;
		}
		trav = (trav)->next;
		count++;
	}
}


int main()
{
	int n,q;
	cin>>n>>q;
	node * head;
	create(head,n);
	while(q--)
	{
		int d;
		cin>>d;
		del(&head,d);
		print(head);
	}
	
	return 0;
}






