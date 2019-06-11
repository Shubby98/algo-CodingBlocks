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



node * merge(node * head1,node * head2)
{
	node* mhead;
	node* tail ;
	if(head1 == NULL)
	{
		return head2;
	}
	if(head2 == NULL)
	{
		return head1;
	}
	if(head1->data > head2->data)
	{
		mhead  =  head2;
		head2= head2->next;
	}
	else
	{
		mhead =  head1;
		head1 =  head1->next;
	}
			
	tail =  mhead;
	//cout<<"till now";
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data > head2->data)
		{
			tail->next  =  head2;
			head2 =  head2->next;
			tail =  tail->next;
			tail->next = NULL;
		}
		else
		{
			tail->next =  head1;
			head1 =  head1->next;
			tail = tail->next;
			tail->next = NULL;
		}
	//	cout<<tail->data<<endl;
	}
	//cout<<"loop";
	
	if(head1 == NULL)
	{
		tail->next =  head2;
	}
	
	if(head2 == NULL)
	{
		tail->next = head1;
	}
	 return mhead;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2;
		cin>>n1;
		node * head1;
		create(head1,n1);
		cin>>n2;
		node * head2;
		create(head2,n2);
		node * head3 = merge(head1,head2);
		print(head3);
	}
	return 0;
}




