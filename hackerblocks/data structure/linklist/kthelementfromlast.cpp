#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node * next;
	node(int data)
	{
		this->data =  data;
	}
};

void create(node * &head)
{
	cout<<"enter data or -1 to exit"<<endl;
	head = NULL;
	int data ;
	cin>>data;
	if(data!=0)
	{
		head = new node(data);
		//head->data =  data;
		head->next = NULL;	
	}	
	if(head!= NULL)
	{
		node * tail = head;
		cin>>data;
		while(data!=-1)
		{
			node * temp = new node(data);
			//temp->data = data;
			temp->next = NULL;
			tail->next = temp;
			tail= temp;
			cin>>data;
		}
	}
	
}

void print(node* &head)
{
	node * trav = head;
	while(trav!=NULL)
	{
		cout<<trav->data<<"-->";
		trav =  trav->next;
	}
	cout<<"NULL"<<endl;
 } 
 
int kthelementfromlast(node * head, int k)
{
	node * trav = head;
	int index=1;
	while(index!=k)
	{
		trav = trav->next;	
		index++;
	} 	
	node * trav1 = head;
	//cout<<trav->data<<endl;
	while(trav->next!=NULL)
	{
		trav1 = trav1->next;
		trav = trav->next;
	}
	return trav1->data;
}
 
 
int main()
{
 	node * head;
	create(head);
	//cout<<"***";
	//print(head);
	int n;
	cin>>n;
	cout<<kthelementfromlast(head,n);
	return 0;
	
	
		
}
 
 
 
 
 
 
 
 
 
 
