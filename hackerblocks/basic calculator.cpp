#include<iostream>

using namespace std;

int main()
{
    char operation;
    long int n1,n2;
    while(1)
    {
        cin>>operation;
        if(operation == 'X' || operation == 'x')
            break;
        
        else if(operation == '+')
            {
                cin>>n1>>n2;
                cout<<n1+n2<<endl;
            }    
        else if(operation == '-')
            {
                cin>>n1>>n2;
                cout<<n1-n2<<endl;
            }
        else if(operation == '*')
            {
                cin>>n1>>n2;
                cout<<n1*n2<<endl;
            }
        else if(operation == '/')
            {
                cin>>n1>>n2;
                cout<<n1/n2<<endl;
            }
        else if(operation == '%')
            {
                cin>>n1>>n2;
                cout<<n1%n2<<endl;
            }
        else
            cout<<"Invalid operation. Try again."<<endl;
    }
	return 0;
}
