#include<iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

struct stack
{
	private:
		node * head;
		int size;
	public:
		bool IsEmpty()
		{
			if(size == 0)
			{
				return true;
			}
			return false;
		}
		
		int top()
		{
			if(!IsEmpty())
			{
				return head->data;
			}
		}
		
		void push(int data)
		{
			node * temp =  new node;
			temp->data =  data;
			temp->next =  head;
			head = temp;
			size++;
			return;
		}
		
		void pop()
		{
			if(IsEmpty())
			{
				return ; 
			}
			node * temp =  head ;
			head = head->next;
			delete temp;
			size--;
			return;
		}
		int Size()
		{
			return size;
		}
};


int main()
{
	stack s;
	s.push(5);
	s.push(8);
	s.push(21);
	s.push(98);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.Size()<<endl;
}



