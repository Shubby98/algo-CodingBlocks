#include<iostream>

using namespace std;

struct node
{
	int data;
	node * next;
	bool visit;
	node(int data)
	{
		this->data =  data;
		visit = false;
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

void print(node* head)
{
	node * trav = head;
	while(trav!=NULL)
	{
		cout<<trav->data<<"-->";
		trav =  trav->next;
	}
	cout<<"NULL"<<endl;
	return;
 } 
 
bool isCircle( node * head)
{
	if(head == NULL )
	{	
		return false;
	}	
	if(head->visit == true)
	{
		return true;
	}
	//cout<<"**";
	head->visit = true;
	return isCircle(head->next);
	
}
 
 int main()
 {
 	node *head;
 	create(head);
 	print(head);
 	
 	//head->next->next->next->next->next->next->next->next->next->next =  head->next->next->next->next->next->next;
 	
 	cout<<isCircle(head);
 }
