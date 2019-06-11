#include<iostream>
#include<string.h>

using namespace std;

string check(string s,int index)
{
    if(s[index] == 'x')
    {
        for(int j = index; j < (int)s.length()-1 ; j++)
        {
            s[j] = s[j+1];
        }
        s[s.length() - 1] = 'x';
    }
    return s;
}

string move(string s,int i)
{
   if(i == s.length() - 1)
   {
       return check(s,i);
   }
   s = move(s,i+1);
   s = check(s,i);
   //cout<<s<<endl;
   return s;
}

int main() {
    string s;
    cin>>s;
    s = move(s,0);
    cout<<s;
	return 0;
}
