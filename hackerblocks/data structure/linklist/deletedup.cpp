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



void removedup(node * head)
{
	node * prev = head;
	head = head->next;
	prev->next = NULL;
	while(head!=NULL)
	{
		if(prev->data == head->data)
		{
			node * temp = head;
			head =  head->next;
			delete temp;
	
		}
		else
		{
			prev->next  =  head;
			head = head->next;
			prev = prev->next;
			prev->next = NULL;
				
		}
		//cout<<"###"<<endl;
		//print(head);
	}
	return;
}

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		node * head;
		create(head,n);
		removedup(head);
		print(head);
	}
}
