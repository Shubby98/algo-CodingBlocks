#include<iostream>

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
 
void del(node ** head,int index)
{
	int count = 2;
	if(index == 1)
	{
		node* temp = (*head);
		*head = temp->next;
		delete temp;
		return;
		
	}
	while(*head!=NULL)
	{
		if(count==index)
		{
			node * temp = (*head)->next;
			(*head)->next =  temp->next;
			delete temp;
			return;
		}
		*head = (*head)->next;
		count++;
	}
}

node * findatpos(node * head,int index)
{
	while(index-- && head )
	{
		head =  head->next;
	}
	return head;
}
/*
void del2(node ** head,int index)
{
	node * del = findatpos(*head,index);
	if(del == *head)
	{
		*head = del->next;
		delete del;
	}
		
}
*/
void insertatpos(node ** head,int data ,int k)
{
	node * temp = new node(data);
	int count = 0;
	node * HEAD =  * head;
	if(k == 0)
	{
		
		temp->next = HEAD->next;
		*head = temp;
		return;
	}
	node* trav = *head;
	while(count!=k-1)
	{
		trav =  trav->next;
		count++;
	}
	temp->next=trav->next;
	trav->next = temp;
	return;
}

int main()
{
	node * head ;
	create(head);
	print(head);
	del(&head,1);
	print(head);
	del(&head,2);
	print(head);
	del(&head,5);
	print(head);
	//insertatpos(&head,21,0);
	//print(head);
	//insertatpos(&head,12,4);
	//print(head);
	//insertatpos(&head,98,9);
	//print(head);	
	
}
