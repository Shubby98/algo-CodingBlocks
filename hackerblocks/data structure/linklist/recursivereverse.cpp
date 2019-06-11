#include<iostream>

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

node * reverse(node * head ,node * &tail)
{
	if(head->next==NULL)
	{
		tail = head;
		return head;
	}
	
	node * newhead = reverse(head->next,tail);
	tail->next = head;
	tail = head;
	tail->next = NULL;
	return newhead;
}

node * reverse2(node * head)
{
	node * trav = head; 
	node *prev = NULL;
	node *next =  NULL;
	
	while(trav!=NULL)
	{
		next = trav->next;
		trav->next = prev;
		
		prev = trav;
		trav = next;
		
	}
	return prev;
}
int main()
{
	int n; 
	cin>>n;
	node * head ;ww
	create(head,n);
	node * tail;
	node * newhead = reverse2(head);
	print(newhead);
}






