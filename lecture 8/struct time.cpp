#include<iostream>

using namespace std;

struct Time
{
	int H,M,S;
	
};

Time * input()
{
	Time * t = new Time;
	cout<<"enter the hours = ";
	cin>>t->H;
	cout<<"enter the min = ";
	cin>>t->M;
	cout<<"enter the seconds = ";
	cin>>t->S;
	return t;
}

void print(Time * t)
{
	cout<<" "<<t->H<<" : "<<t->M<<" : "<<t->S<<endl;
	return;
}

Time* diff(Time *t1,Time* t2)
{
	int mcount= 0,hcount = 0;
	Time * t = new Time;
	(*t).H = (*t1).H - (*t2).H;
	(*t).M = (*t1).M - (*t2).M;
	(*t).S = (*t1).S - (*t2).S;
	if(t->S<0)
	{
		mcount++;
		t->S += 60;	
	}
	if(t->M<0)
	{
		hcount++;
		t->M += 60;
	}
	(t->M) -= mcount;
	(t->H) -= hcount;
	return t;
}

int main()
{
	Time * t1 = input();
	print(t1);
	Time * t2 = input();
	print(t2);
	Time *t3 = diff(t1,t2);
	print(t3);
}
