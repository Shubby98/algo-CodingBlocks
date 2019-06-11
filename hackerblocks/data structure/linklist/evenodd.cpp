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

node * returntail(node * head)
{
    while(head->next!=NULL)
    {
        head = head->next;
    }
    return head;
}

void insertAtTail(node **head,int data)
{
    node * temp = new node(data);
    if(*head==NULL){
        *head = temp;
        return;
    }
    node * tail = *head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = temp;
    return;
}


node * oddeven(node * trav)
{
   // cout<<"ood even chalgya"<<endl;
    node * odd = NULL;
    node * even = NULL;
    while(trav!=NULL)
    {
        //cout<<trav->data<<" ";
        if( trav->data%2==0 )
        {
            insertAtTail(&even,trav->data);
        }
        else
        {
            insertAtTail(&odd,trav->data);
        }
        trav = trav->next;
    }
    if(odd!=NULL && even!=NULL)
    {
        node * tail = returntail(odd);
        tail->next = even;
        return odd;
    }
    else if(odd==NULL)
    {
        return even;
    }
    else if(even == NULL)
    {
        return odd;
    }

}


int main()
{
	int n;
	cin>>n;
	node *head;
	create(head,n);
	//cout<<"linklist bangyi"<<endl;
    node * head2 = oddeven(head);
    //cout<<"odd even hogya"<<endl;
	print(head2);

}








