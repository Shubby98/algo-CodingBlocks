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
 
int len(node* head)
{
	int count = 0;
	while((head) != NULL)
	{
		count++;
		head = head->next;
	}
	//count++;
	return count;
}

node * mid(node * head, int len)
{
	int mid =  (len+1)/2;
	int index = 1;
	while(index != mid)
	{
		index++;
		head =  head->next;
	}
	return head;
}




bool find(node * head,int k)
{
	if(head == NULL)
	{
		return false;
	}
	if(head->data ==  k)
	{
		return true;
	}
	
	
	return find(head->next,k);
}

//void swap(node *head,node* x)

//void bubblesort()

node* fromend(node * head,int &i)
{
	if( head == NULL)
	{
		i--;
		return NULL;
	}
	node* temp = fromend(head->next,i);
	if( i == 0)
	{
		return head;
	}	
	i--;
	return temp;
}

//merge


int main()
{
	node *head;
	create(head);
	print(head);
	//cout<<len(head);
	//int lenght = len(head);
	//node* midterm = mid2(head);
	//cout<<(midterm->data)<<endl;
	cout<<"****";
	int num;
	cin>>num;
	//cout<<find(head,num);
	node * ele = fromend(head,num);
	cout<<(ele->data)<<endl;
	
	return 0;
	
 		
}
