#include<iostream>
#include<stack>

using namespace std;

bool redundant(string s)
{
    stack<char> stk;
    int i = 0;
    while(s[i]!='\0')
    {
        if(s[i] == ')' )
        {
            int count = 0;
            while(stk.top() != '(' ){
                count++;
                stk.pop();
            }
            stk.pop();
            if(count==0)
            {
                return false;
            }
        }
        else
        {
            stk.push(s[i]);
        }
        i++;
    }
    return true;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(redundant(s))
            cout<<"NOT Duplicate"<<endl;
        else
            cout<<"Duplicate"<<endl;
    }
    return 0;
}
