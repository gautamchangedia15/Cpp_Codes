#include<iostream>
using namespace std;

class matrix
{
    private:
    int a[10][10];
    int m,n,s=0;
    public:
    void getdata();
    void setdata();
    int sum();
};
void matrix::getdata()
{
    cout<<"Enter no of rows and columns: ";
    cin>>m>>n;
    cout<<"Enter elements of matrix: ";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    
}
void matrix::setdata()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                s=s+a[i][j];
            }
        }
    }
   
}
int matrix::sum()
{
    return s;
}
int main()
{
    matrix a;
    a.getdata();
    a.setdata();
     cout<<"Sum: "<<a.sum();
    return 0;
}
