#include <iostream>
using namespace std;

bool binarySearch(int* arr, int s, int e,int key)
{
    if(s>e)
        return 0;
    int mid=s+(e-s)/2;
    if(arr[mid]==key)
        return 1;
    
    else
    {
        bool ans;
        if(arr[mid] > key)
            ans=binarySearch(arr,s,mid-1,key);
        else
            ans=binarySearch(arr,mid+1,e,key);
        
        return ans;
    }
}

bool linearSearch(int *arr,int size,int key)
{
    if(size==0)
        return 0;
    if(size==1)
        return arr[0]==key;
    
    if(arr[0]==key)
        return true;
        
    else
    {
        bool ans=linearSearch(arr+1,size-1,key);
        return ans;
    }
}
int sumArray(int arr[],int size)
{
    if(size==1)
    {
        return arr[0];
    }
    
    int sum=arr[0]+sumArray(arr+1,size-1);
    return sum;
}
int main()
{
    cout<<"Hello World \n";
    int arr[5]={1,2,3,5,5};
    int size=5;
    cout<<"Sum: "<<sumArray(arr,size);
    
    int key;
    cout<<"\nEnter key to find: ";
    cin>>key;
    
    if(linearSearch(arr,5,key))
        cout<<"Found by Linear Search !"<<endl;
    else
        cout<<"Not found by Linear Search !"<<endl;
        
    int s=0,e=4,mid=s+(e-s)/2;
     if(binarySearch(arr,s,e,key))
        cout<<"Found by Binary Search !"<<endl;
    else
        cout<<"Not found by Binary Search !"<<endl;
    return 0;
}