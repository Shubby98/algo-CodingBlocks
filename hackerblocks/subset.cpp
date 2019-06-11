#include<iostream>

using namespace std;

void swap(int arr[],int i,int j)
{
	int temp = s[i];
	s[i] = s[j];
	s[j] =temp;

	return;
}

int main()
{
	string s;
	cin>>s;
	permutation(s,0,s.length());
	//swap(s,1,2);
	
	
}
