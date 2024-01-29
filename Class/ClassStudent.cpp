//Create a class named 'Student' with a string variable 'name' and an integer variable 'roll_no'. 
//Assign the value of roll_no as '2' and that of name as "John" by creating an object of the class Student.
#include<iostream>
using namespace std;
class Student
{
    int roll_no;
    string name;
    friend Student teacher(Student );
    public: 
    void getData(string n,int rn);
    void printData();
};
void Student::getData(string n,int rn)
{
    roll_no=rn;
    name=n;
}
void Student::printData()
{
    cout<<"Roll no: "<<roll_no<<endl;
    cout<<"Name: "<<name;
}
Student teacher(Student s4)
{
    Student s3;
   s3.getData("Raju",10);
   return s3;
}

int main()
{
    Student s1,s2;
    s1.getData("Jay",2);
    s1.printData();
    s2=teacher(s1);
    s2.printData();
    return 0;
}