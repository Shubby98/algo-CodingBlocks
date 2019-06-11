#include<iostream>
#include<stack>

using namespace std;

void reverseSTACK( stack <int> &s)
{
    if(s.empty())
    {
        s.push(9999);
        return;
    }
    int elmt = s.top();
    s.pop();
    reverseSTACK(s);
    cout<<elmt<<endl;
}

int main()
{
    int n;
    cin>>n;
    stack <int> s;
    while(n--)
    {
        int num;
        cin>>num;
        s.push(num);
    }
    reverseSTACK(s);
    return 0;

}
