#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    /*    
    //Approach 1:
    int n,i=0,digit,ans=0;
    cout<<"Enter decimal number: ";
    cin>>n;
    int arr[30];
    while(n!=0)
    {
        digit=n%2;
        arr[i]=digit;
        n=n/2;
        i++;
    }
    cout<<"Binary: ";
    for(int t=i-1;t>=0;t--)
    {
        cout<<arr[t];
    }
    return 0;
    */
    

   //Approach 2: 

   int n,ans=0,bit=0,i=0;
   cout<<"Enter decimal number: "<<endl;
   cin>>n;
   while(n!=0)
   {
        bit=n & 1;
        ans=(bit*pow(10,i))+ans;
        n=n>>1;
        i++;
   }
   cout<<"Binary Number: "<<ans;
   return 0;

    /*
    //for negative numbers
    int n,ans=0,place_val=1;
    cout<<"Enter negative decimal number: ";
    cin>>n;
    n=abs(n);
    int twos=~n+1; //twos's compliment
    while(twos!=0)
   {
       int bit=twos & 1;
        ans=(bit*place_val)+ans;
        twos=twos>>1;
        place_val*=10;
   }
   cout<<"Binary Number: "<<ans;*/

}
