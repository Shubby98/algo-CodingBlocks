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

node * findatpos(node * head,int index)
{
	while(index-- && head )
	{
		head =  head->next;
	}
	return head;
}
/*
void swap(node * &head , int i ,int j)
{
	if(i == 0 && j == 1)
	{
		node * a = head;
		node * b = a->next;
		node* bnext = b->next;
		a->next = bnext;
		head = b;
		b->next = a;
	}
	else if( i == 0 || j == 0)
	{
        if(j==0)
        {
            int temp = i;
            i = j;
            j = temp;

        }
		node * a = head;
		node * bprev = findatpos(head , j - 1);
		node* b = bprev->next;
		node * bnext =b->next;
		head = b;
		b->next = a->next;
		bprev->next = a;
		a->next = bnext;
		return;
	}
	else if(j-i==1)
	{
        node * aprev = findatpos(head,i-1);
        node * a = aprev->next;
        node * b = a->next;
        node * bnext = b->next;
        aprev->next = b;
        b->next = a;
        a->next = bnext;
        return;
	}
	else
	{
        node * prev1 = findatpos(head,i-1);
        node * prev2 = findatpos(head,j-1);
        node * a = prev1->next;
        node * b =  prev2->next;
        node * bnext = b->next;
        prev1->next = b;
        b->next = a->next;
        prev2->next = a;
        a->next = bnext;
    }
}
*/

node * find(node * head ,int data)
{
    if(head==NULL)
    {
        return head;
    }
    while(head!=NULL)
    {
        if(head->data == data)
        {
            return head;
        }
        head = head->next;
    }
}

void swap(node * head , int x,int y)
{
    node *xptr = find(head,x);
    node *yptr = find(head,y);
    if(xptr!=NULL && yptr!=NULL)
    {
        int temp = xptr->data;
        xptr->data = yptr->data;
        yptr->data = temp;
    }

}


int main()
{
    int n;
    cin>>n;
    node * head=NULL;
    create(head,n);
    int i,j;
    cin>>i>>j;
    swap(head,i,j);
    print(head);
    return 0;

}
/*
5
1 2 3 4 5
*/
