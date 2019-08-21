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
void create(node * &head,int n)
{

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
		cout<<trav->data<<"-->";
		trav =  trav->next;
	}
	cout<<"NULL"<<endl;
 }

void intersection(node * head1 , node * head2)
{
	unordered_map <int , bool> visited;
	while(head1!=NULL)
	{
		int num = head1->data;
		visited[num] = true;
		head1 = head1->next;
	}
	while(head2!=NULL)
	{
        int num = head2->data;
        if(visited.find(num)!=visited.end())
        {
            cout<<num<<endl;
            return;
        }
        head2 = head2->next;
	}
	return;

}

int main()
{
    int n1,n2;
 	node* head1;
 	node* head2;
 	cin>>n1;
	create(head1,n1);
	cin>>n2;
	create(head2,n2);

	intersection(head1,head2);
	return 0;


}










