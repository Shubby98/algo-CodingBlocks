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

node * mid2( node * head)
{
	node *i = head , *j =  head;
	while(j->next != NULL && j->next->next != NULL)
	{
			//cout<<i->data<<endl;
			j =  j->next->next;
			i =  i->next;
			
	}
	//cout<<"***";
	return i;
}
node * findatpos(node * head,int index)
{
	while(index--)
	{
		head =  head->next;
	}
	return head;
}


node * merge(node * head1,node * head2)
{
	node* mhead;
	node* tail ;
	if(head1 == NULL)
	{
		
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

node * reversek()

int main()
{
	node * head1;
	node * head2;
	create(head2);
	print(head2);
	//create(head2);
	//print(head2);
	//cout<<"***";
	node * head3 =  mergeSort(head2,0,5);
	//cout<<"####";
	print(head3);
	return 0;		
}


/*
1 3 5 7 -1
2 4 6 8 -1
*/






