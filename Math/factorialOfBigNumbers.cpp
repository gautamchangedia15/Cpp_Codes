#include<iostream>
using namespace std;

int fact(int a,int m)
{
    int ans=a%m;
    for(long long int i=a-1;i>=1;i--)
    {
        ans=(1LL*(ans%m)*(i%m))%m;
    }
    return ans;
}
int main()
{
    cout<<"Hi, Enter a number to find its factorial in mod 10^9+1: ";
    int a,m=1000000007;
    cin>>a;
    cout<<fact(a,m);
    return 0;
}