#include<iostream>
#include<stack>

using namespace std;

void insert_sorted(stack <int> &s,int data)
{
    if(s.empty())
    {
        s.push(data);
        return;
    }
    int top = s.top();
    s.pop();
    if(top>data)
        insert_sorted(s,data);
    else{
        s.push(top);
        s.push(data);
        return;
    }
    s.push(top);
    return;



}

void sortstack(stack <int> &s)
{
    if(s.empty())
    {
        return ;
    }

    int top = s.top();
    s.pop();
    sortstack(s);
    insert_sorted(s,top);
    return;

}

int main()
{
    int t;
    cin>>t;
    stack <int> s;
    while(t--)
    {
        int num;
        cin>>num;
        s.push(num);
    }
    sortstack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
