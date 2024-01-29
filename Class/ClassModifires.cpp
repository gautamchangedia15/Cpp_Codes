#include<iostream>
using namespace std;
class hostel
{
    private:
        string rp;  //rp stands for room partner;
    public: 
        int n;      //number of people in room
        int rn;     //rn-room number
    void setData(string ,int ,int );
    void getData();
};
int main()
{
    hostel WIT;
    WIT.setData("yash",2,106);
    WIT.getData();
    //WIT.rp="Gautam";    this will give error as rp is in private

    return 0;
}
void hostel::setData(string rp1,int n1,int rn1)
{
    rp=rp1;
    n=n1;
    rn=rn1;
    
}
void hostel::getData()
{
    cout<<"\nRoom Mate: "<<rp;
    cout<<"\nNumber of people in room: "<<n;
    cout<<"\nRoom Number: "<<rn;

}
