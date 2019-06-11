#include<iostream>
#include<utility>

using namespace std;
struct node{
    int data;
    node* next;
    node * prev;
    node(){}
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void createll(pair <node* ,node* > &ll,int n)
{

    if(n==0)
    {
        ll.first = NULL;
        ll.second = NULL;
        return ;
    }
    node* head ;
    int data;
    cin>>data;
    head = new node(data);
    node * tail = head;
    n--;
    while(n--)
    {
        int data;
        cin>>data;
        node * temp = new node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    ll.first = head;
    ll.second = tail;
    return;
}

void print(pair <node *,node *> ll)
{
    node * trav = ll.first;
    cout<<"from front"<<endl;
    while(trav!=NULL)
    {
        //cout<<"**"<<endl;
        cout<<trav->data<<" ";
        trav = trav->next;
    }
    cout<<"from back"<<endl;
    trav = ll.second;
    while(trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav = trav->prev;
    }
    return;
}

bool IsPalindrome(pair <node *,node *> ll)
{
    node * trav = ll.first;
    node * travb = ll.second;
    while(trav!=NULL || travb!=NULL)
    {
        if(trav->data != travb->data)
        {
            return false;
        }
        trav = trav->next;
        travb = travb->prev;
    }
    return true;
}


int main()
{
    int n;
    cin>>n;
    pair <node *,node *> ll;
    createll(ll,n);
    if(IsPalindrome(ll))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
