#include<iostream>
using namespace std;

long int pow(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int ans;
    int remaining=pow(a,b/2);
    if(b&1)
    {
        //odd number
        ans=a*remaining*remaining;
    }
    else
    {
        //even number
        ans=remaining*remaining;
    }

    return ans;
}

int main()
{
    int a,b;
    cout<<"Enter a & b ";
    cin>>a>>b;
    cout<<a<<"^"<<b <<"= "<<pow(a,b);
    return 0;
}