#include<iostream>
#include<stack>
using namespace std;

bool isBalance(string eq)
{
	stack<char> s;
	int i = 0;
	while(eq[i]!='\0')
	{
		if( eq[i] == '[' || eq[i] == '{' || eq[i] == '(' )
		{
			s.push(eq[i]);
		}
		else
		{
			if((eq[i]==')' && s.top()=='(') || (eq[i]==']' && s.top()=='[') || (eq[i]== '}' && s.top()=='{'))
			{
				
				s.pop();
				
			}
			else
			{
				return false;
			}
		}
		i++;
	}
	if(s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	string eq;
	
	cin>>eq;
	
	if(isBalance(eq))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
}
