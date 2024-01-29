#include<iostream>
using namespace std;

void solve(int*arr,int size)
{
    if(size==0||size==1)
        return;
    
    int miniIndex=0,j=1;
    for(;j<size;j++)
    {
        if(arr[j]<arr[miniIndex])
            miniIndex=j;
    }

    swap(arr[0],arr[miniIndex]);

    solve(arr+1,size-1);
}
int main()
{
    int arr[5]={5,3,1,2} ;
    int size=4;
    solve(arr,size);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}