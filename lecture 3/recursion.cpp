#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int multiply(int a,int b)
{
	if(b==1)
	{
		return a;
	}
	return a + multiply(a,b-1);
}

bool binarysearch(int arr[],int l,int r,int x)
{
	if(l == r)
	{
		if(arr[l]==x)
			return true;
		else 
		return false;
	}
	int mid = l + (r-l)/2;
	if(arr[mid]==x)
	{
		return true;
	}
	if(x>arr[mid])
	{
		return binarysearch(arr,mid+1,r,x);
	}
	if(x<arr[mid])
	{
		return binarysearch(arr,l,mid-1,x);
	}
	
	
}

void print(int arr[],int n)
{
	for(int i = 0; i<n;i++)
		cout<<arr[i]<<" ";
		
	cout<<endl;
}

void bubblesort(int arr[],int n,int i)
{
	print(arr,3);
	if(n==0||n==1)
	{
		return ;
	}
	
	if(n-1 == i)
	{
		bubblesort(arr,n-1,0);
		return;
	}
	
	if(arr[i]>arr[i+1])
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}
	bubblesort(arr,n,i+1);
	
}

int string2int(string s,int i)
{
	if(i == 0)
	{
		return 0;
	}
	
	int x = i + 10*string2int(s,i-1);
	cout<<x<<endl;
	return x;
	
}

int stringtoint(string s)
{
	if(s[1]=='\0')
	{
		int n = s[0] - 48;
		cout<<s[0]<<endl;
		return n;
	}
	if(s[0]=='-')
	{
		int len = s.length();
		int k = stringtoint(s.substr(1,len+1));
		return -k;
	}
	
	int n = s[0]-48;
	int len = s.length();
	int k = stringtoint(s.substr(1,len+1));
	int final = k + (n*pow(10,len-1));
	cout<<n<<"	"<<len<<"	"<<k<<"		"<<final<<endl;
	return final;
	/*if(s.length()>0)
	{
		int t=int(s[0]-'0');
		int n=s.length();
		string str=s.substr(1,n);
		int k=stringtoint(str);
		return (k+(t*pow(10,n-1)));
	}
	return 0;*/
}

void permutation(int arr[],int n, int i)
{
	if(n == i)
	{
		print(arr,n);
		return;
	}
	for(int j = i;j<n;j++)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] =temp;
		
		permutation(arr,n,i+1);
		
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] =temp;
		
		
	}
	
	return;
}

void towerofhanoi(int n,char source,char destination,char helper)
{
    if(n == 1)
    {
        cout<<"Moving ring "<<n<<" from "<<source<<" to "<<destination<<endl;
    	return;
	}
    towerofhanoi(n-1,source,helper,destination);
    cout<<"Moving ring "<<n<<" from "<<source<<" to "<<destination<<endl;
    towerofhanoi(n-1,helper,destination,source);
    return;
    
}


int main()
{
	int arr[10] = {7,1,3} ;
	string s = "-12345";
	char ch[5] = {'1','2','3','4'};
	//cout<<multiply(5,6)<<endl;	
	//cout<<binarysearch(arr,0,8,65);
	//bubblesort(arr,3,0);
	//print(arr,3);	
	//cout<<string2int(s,5)<<endl;
	//int p=stringtoint(s);
	//cout<<p;
	//permutation(arr,3,0);
	towerofhanoi(3,'A','C','B');
}
