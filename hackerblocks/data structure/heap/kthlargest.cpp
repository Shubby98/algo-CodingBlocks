#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    priority_queue <int,vector<int>,greater<int> > pq;
    for(int i = 0;i<n;i++)
    {
        if(pq.size()<k)
            pq.push(arr[i]);
        if(pq.size()==k)
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout<<pq.top()<<endl;
}
