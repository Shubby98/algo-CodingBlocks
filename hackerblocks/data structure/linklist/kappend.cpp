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

void Kappend(node* &head,int k)
{
	node * trav = head;
	int n = k;
	while(n--)
	{
        //cout<<n<<endl;
		trav =  trav->next;
	}
	//cout<<"value of trav = "<<trav->data<<endl;
	node * prev = head;
	//trav = trav->next;
	while(trav->next!=NULL){
		trav = trav->next;
		prev = prev->next;
	}
	//cout<<"value of trav after while= "<<trav->data<<endl;
    //cout<<"value of prev after while= "<<prev->data<<endl;

	trav->next = head;
	head =  prev->next;
	prev->next = NULL;
    return ;
	//head =  temp;
	//cout<<trav->data<<endl;
	//return head;
}


int main()
{

		int n;
		cin>>n;
		node * head1;
		create(head1,n);
		int k;
		cin>>k;
		Kappend(head1,k);
		print(head1);

}




