#include<iostream>

using namespace std;

void swap(int x,int y)
{
	int *ptr1 = x;
	int *ptr2 = y;
	
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;
	
	
}

int main()
{
	int x = 10;
	int y = 20;
	
	swap(&x,&y);
	cout<<x<<" "<<y;
}
