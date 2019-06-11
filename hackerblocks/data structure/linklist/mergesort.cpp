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

node * findatpos(node * head,int index)
{
	while(index--)
	{
		head =  head->next;
	}
	return head;
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


node * mergeSort( node * head,int start , int end)
{
	if(start>end)
	{
		return NULL;
	}
	if(start == end)
	{
		return head;
	}
	
	int mid =  (start + end)/2;
	node * midNode = findatpos(head, (mid-start));
	node * head1 = head;
	node * head2 =  midNode->next;
	midNode->next = NULL;
	head1 = mergeSort(head1,start,mid);
	head2 =  mergeSort(head2,mid+1,end);
	node* nwhead =  merge( head1, head2);
	return nwhead;
}



int main()
{
	int t;
	cin>>t;
	node * head;
	create(head,t);
	node * head2 = mergeSort(head,0,t);
	print(head2);
	return 0;
}

