#include<iostream>
#include<time.h>
#include<limits.h>
using namespace std;

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

int count(int n)
{
    if(n==1)
    {
        return 0;
    }
    int a = 1000,b = 1000,c = 1000;
    if(n%3==0)
    {
        a = count(n/3);
    }

    if(n%2==0)
    {
        b = count(n/2);
    }

    c = count(n-1);
    return min(a,min(b,c))+1;


}


int countdp(int n)
{
    int arr[n+1] = {-1,0,1,1};
    for(int i = 4;i<=n;i++)
    {
        int a = INT_MAX,b = INT_MAX,c = INT_MAX;
        if(n%3==0)
        {
            a = arr[i/3];
        }

        if(n%2==0)
        {
            b = arr[i/2];
        }

        c = arr[i-1];
        arr[i] = min(a,min(b,c))+1;
    }
    return arr[n];
}

int coin(int n)
{
    i

}

int main()
{
    //int start = clock();
    cout<<countdp(10)<<endl;
    //int endt = clock();
    //cout<<endt-start<<endl;
    return 0;
}





