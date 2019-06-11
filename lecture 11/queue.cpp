#include<iostream>

using namespace std;

struct node
{
	int data;
	node * next;
	node(int data)
	{
		this->data =  data;
		this->next = NULL;
	}
};

class Queue
{
	
	node * front ;
	node * rear ;
	int curr_size;
	int max_size ;
	
	public:
	Queue(int size)
	{
		front = NULL;
		rear = NULL;
		curr_size = 0;
		max_size = size;
	}
	
	bool IsEmpty()
	{
		return curr_size==0;
	}
	
	bool IsFull()
	{
		return curr_size==max_size;
	}
	
	void enqueue(int data)
	{
		if(!IsFull())
		{
			node * temp = new node(data);
		if(curr_size == 0)
		{
			front = temp;
			rear = temp;
			curr_size++;
			return;
		}
		else
		{
			rear->next =  temp;
			rear =  temp;
			curr_size++;
			return;
		}
		}
	
		else
		{
			cout<<"queue is full"<<endl;
			return;
		}
	}
	
	void dequeue()
	{
		node * temp = front;
		if(!IsEmpty())
		{
			front = front->next;
			delete temp;
			curr_size--;  
		}
		else
		{
			cout<<"Queue is Empty"<<endl;
		}
	}

	int size()
	{
		return curr_size;
	}
	
	int top()
	{
		if(front!=NULL)
		{
			return front->data;
		}
	}
};

int main()
{
	
	Queue Q(10);
	Q.enqueue(21);
	Q.enqueue(12);
	Q.enqueue(19);
	Q.enqueue(98);
	cout<<Q.top()<<"	"<<Q.size()<<endl;
	Q.dequeue();
	cout<<Q.top()<<"	"<<Q.size()<<endl;
	Q.dequeue();
	cout<<Q.top()<<"	"<<Q.size()<<endl;
	Q.dequeue();
	
}
