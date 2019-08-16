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
   // cout<<"print chla";
	node * trav = head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav =  trav->next;
	}
	cout<<endl;
}

void display(node* head, node* tail)
{
    //cout<<"Display chla"<<endl;
    while(head!=tail)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<head->data<<endl;
    return;
}

pair <node*,node*> reve(pair<node*,node*> p,bool flag = false)
{
    //cout<<"reverse chlr rha hai"<<endl;
    node* head = p.first;
    node * tail = p.second;
    if(head == tail)
    {
        return make_pair(tail,head);            // return pair of new link list if head and tail are same
    }
    //cout<<head->data<<" : "<<tail->data<<endl;

    pair <node*,node*> nll = reve(make_pair(head->next,tail));
    node* nhead = nll.first;
    node* ntail = nll.second;
    ntail->next = head;                         // linking new tail with old head head
    if(flag)
    {
        ntail->next->next = NULL;
    }
    return make_pair(nhead,ntail->next);         //returning new head and
}

node* Kreverse(node * head,int k)
{
    //cout<<"Kreverse chla with head = "<<head->data<<endl;
    node * tail = head;
    int it = k;
    while(--it)
    {
        //cout<<"value of it"<<it<<endl;
        //cout<<"value of tailnext"<<tail->next<<endl;
        if(tail->next!=NULL)
        {
            tail = tail->next;
        }
    }
    if(tail->next==NULL)
    {
        //cout<<"NULLaa hogya"<<endl;
      //  display(head,tail);
        pair <node*,node*> ll = reve(make_pair(head,tail),true);
        //print(ll.first);
        //cout<<"he is back"<<ll.first<<endl;
        return ll.first;
    }
    //display(head,tail);

    node * prev_ll_head = Kreverse(tail->next,k);
    pair <node*,node*> curr_ll = reve(make_pair(head,tail),true);

    //display(curr_ll.first,curr_ll.second);

    node * curr_ll_tail = curr_ll.second;
    (curr_ll_tail)->next = prev_ll_head;
    //print(curr_ll.first);

    return curr_ll.first;

}




int main()
{

		int n,k;
		cin>>n>>k;
		node * head;
		create(head,n);

		//cout<<"input hogya"<<endl;
		//print(head);
		node * new_head = Kreverse(head,k);
		//cout<<"katm hogya"<<endl;
		print(new_head);

}




