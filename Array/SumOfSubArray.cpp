#include<iostream>
using namespace std;

int main()
{
    int n,i,j,counter=0,sum=0;
    cout<<"Enter nth term of array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int curr=0;
    for(i=0;i<n;i++)
    {
        curr=0;
        for(j=i;j<n;j++)
        {
            curr+=a[j];
            sum+=curr;
            cout<<curr<<endl;
            counter++;
        }
    }
    cout<<"No of subarrays: "<<counter<<endl<<"Sum of all subaarays: "<<sum;
    //No of subaarys= n*(n+1)/2
    return 0;
}