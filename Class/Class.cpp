#include<iostream>
using namespace std;
class cars{
    public:
    string colour;
    int noofdoors;
};
int main()
{
    cars toyoto;
    cars suzuki;
    toyoto.colour="Blue";
    toyoto.noofdoors=6;
    suzuki.colour="White";
    suzuki.noofdoors=4;
    cout<<"Toyoto\n Colour: "<<toyoto.colour<<"\nNo of doors: "<<toyoto.noofdoors;
    cout<<"\n\nSuzuli\n Colour: "<<suzuki.colour<<"\nNo of doors: "<<suzuki.noofdoors;

}