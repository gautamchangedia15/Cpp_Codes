#include<iostream>
using namespace std;

void solve(int *arr,int size)
{
    if(size==0 || size==1)
        return;
    
    //Handle first iteration
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    //Baki Recursion Dekh lenga
    solve(arr,size-1);
}
int main()
{
    int arr[5]={2,5,6,4,1} ;
    int size=5;
    solve(arr,size);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}