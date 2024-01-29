           #include<iostream>
using namespace std;

void print(int *arr,int size)
{
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    } cout << endl;  
}
void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int* first=new int[len1];
    int* second= new int[len2];
    //copy values
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
   
    k=s;
    int index1=0;
    int index2=0;
    while(index1<len1 &&  index2<len2)
    {
        if(first[index1]<second[index2])
            arr[k++]=first[index1++];
        else
            arr[k++]=second[index2++];
    } 

    while(index1<len1){
          arr[k++]=first[index1++];
    }
    while(index2<len2){
        arr[k++]=second[index2++];
    }
    
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s,int e)
{
    if(s>=e)
        return;
    
    int mid=s+(e-s)/2;

    //left
    mergeSort(arr,s,mid);

    //right
    mergeSort(arr,mid+1,e);

    //sort the left and right array
    merge(arr,s,e);
}
int main()
{
    int arr[6]={10,6,3,2,4,8};
    int size=6;
    mergeSort(arr,0,size-1); 

    print(arr,size);  

    return 0;
}