#include<iostream>
using namespace std;

int partition(int* arr,int s,int e)
{
    //count number of smaller numbers than first number
    int lessCount=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<= pivot)
            lessCount++;
    }

    //right location of  pivot index 
    int pivotIndex=s+lessCount;

    //place first number at its right position
    swap(arr[s],arr[pivotIndex]);

    //keep all number to left smaller than pivot and greater to right
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<= pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
    } 

    return pivotIndex;
}
void solve(int*arr, int size,int s,int e)
{
    //base case
    if(s>=e)
        return;
    
    //partition of array
    int p=partition(arr,s,e);

    //Recursive call
    solve(arr,size,s,p-1);
    solve(arr,size,p+1,e);


}
int main()
{
    int arr[6]={0 ,9 ,-4 ,19 ,-9 ,-7} ;
    int size=6;
    solve(arr,size,0,size-1);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

