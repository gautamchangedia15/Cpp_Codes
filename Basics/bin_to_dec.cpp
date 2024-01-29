#include<iostream>
#include<math.h>
using namespace std;


int main()
{
    int n,ans=0,digit,i=0;
    cout<<"Enter binary num:";
    cin>>n;
    while(n!=0)
    {
        digit=n%10;
        ans=ans+(digit*pow(2,i));
        n=n/10;
        i++;
    }
    cout<<"Decimal: "<<ans;
    return 0;
}