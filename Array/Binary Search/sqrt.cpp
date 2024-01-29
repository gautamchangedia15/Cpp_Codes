#include<iostream>
using namespace std;

int tempSol(int n)
{
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    int ans=0;
    while(s<=e)
    {
        long long int square=mid*mid;
        if(square==n)
            return mid;
        else if(square > n)
            e=mid-1;
        else
        {
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
double precisedSol(int n,int temp,int preci)
{
    double factor=1;
    double ans=temp;
    for(int i=0;i<preci;i++)
    {
        factor=factor/10;
        for(double j=ans;(j*j)<n; j=j+factor )
             ans=j;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int temp=tempSol(n);  //will give non decimal value
    cout<<"Ans: "<<precisedSol(n,temp,3);
    return 0;
}