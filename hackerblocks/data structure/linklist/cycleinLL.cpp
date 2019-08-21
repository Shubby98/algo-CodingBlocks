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
//	cout<<"enter data or -1 to exit"<<endl;
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
 
void cycle(node * head)
{	
	//cout<<"cycle"<<endl;
	//cout<<head->data;
	bool visited[100000] = {false};
	while(head!=NULL)
	{
		int num = head->data;
		if(visited[num])
		{
			return;
		}
		visited[num] = true;
		cout<<num<<" ";
		head = head->next;
	}
	return;
	
}
 
int main()
{
 	node * head;
	create(head);
	cycle(head);
	return 0;
	
		
}
 
 
 
 
 
 
 
 
 
 
