#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"enter n th ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
   
    int largest=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>largest)
        largest=a[i];
        cout<<" "<<largest;
    }
    return 0;
}  