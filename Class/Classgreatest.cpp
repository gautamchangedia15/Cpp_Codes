#include<iostream>
using namespace std;
class B;
class A
{
    private: 
    int x;
    public:
    void getData();
    void display();
    friend void greatest(A,B);
    
};
class B
{
    private: 
    int y;
    public:
    void getData();
    void display();
    friend void greatest(A,B);
};
void A::getData()
{
    cout<<"Enter x: ";
    cin>>x;
}
void B::getData()
{
    cout<<"Enter y: ";
    cin>>y;
}
void greatest(A t1,B t2)
{
    if(t1.x>t2.y)
    {
        cout<<"Greates: "<<t1.x;
    }
    else 
    cout<<"Greatest: "<<t2.y;
}
int main()
{
    A n1;
    B n2;
    n1.getData();
    n2.getData();
    greatest(n1,n2);
    return 0;
}