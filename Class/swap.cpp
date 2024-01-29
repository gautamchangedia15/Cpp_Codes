#include<iostream>
using namespace std;

class Numbers
{
    private:
    int x;
    int y;
    public:
    void getData();
    void swap();
    void printdata();
};
void Numbers::getData()
{
    cout<<"Enter a= ";
    cin>>x;
    cout<<"Enter b= ";
    cin>>y;
}
void Numbers::swap()
{
    x=x+y;
    y=x-y;
    x=x-y;
}
void Numbers::printdata()
{
    cout<<"a= "<<x<<" b= "<<y;
}
int main()
{
    Numbers a;
    a.getData();
    cout<<"Numbers before swaping: ";
    a.printdata();
    a.swap();
    cout<<"\nNumbers after swaping: ";
    a.printdata();
    return 0;
}