    #include<iostream>
    #include<stack>

    using namespace std;

    void stockspan(int arr[],int n)
    {
        stack <int> s;

        for(int i = 0;i<n;i++)
        {
            while(!s.empty() && arr[i]>arr[s.top()])
            {
                s.pop();
            }
            if(s.empty())
            {
                cout<<i+1<<" ";
            }
            else
            {
                cout<<i-s.top()<<" ";
            }

            s.push(i);

        }
    }

    int main()
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n;i++)
        {
            cin>>arr[i];
        }
        stockspan(arr,n);
        return 0;
    }
