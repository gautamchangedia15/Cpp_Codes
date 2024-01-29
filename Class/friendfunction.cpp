#include<iostream>
#include<math.h>
using namespace std;

class Distance
{
    int x,y;
    public:
    Distance(int,int);
    void print();
    friend int Calculate(Distance,Distance);
};
Distance::Distance(int p,int q)
{
    x=p;
    y=q;
}
int Calculate(Distance d1,Distance d2)
{
    int a=d2.x-d1.x;
    int b=d2.y-d1.y;
    int sum=sqrt(pow(b,2)+pow(a,2));
    return sum;
}
void Distance::print(void)
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}
int main()
{
    Distance a(0,1);
    Distance b(0,6);
    a.print();
    b.print();
    cout<<"Distance: "<<Calculate(a,b);
    return 0;
}