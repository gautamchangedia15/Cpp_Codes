#include<iostream>
#include<stack>
using namespace std;
//T.c. for push,pop or any function is O(1)
class Stack
{
    //Attributes
    public:
        int *arr;
        int top;
        int size;

    //Methods
    Stack(int size){
        this->size=size;
        arr=new int(size);
        top=-1;
    }

    void push(int x) 
    {
         if(size-top>1)
         {
            arr[++top]=x;
         }
         else
         {
           cout<<"Stack Overflow !"<<endl;  
         }
    }
    void pop()
    {
        if(!isEmpty())
        {
            cout<<arr[top--]<<" removed from Stack";
            return;
        }
        else{
            cout<<"Stack is Empty";
            return;
        }
    }
    bool isEmpty()
    {
        if(top==-1) return true;
        else false;
    }
    int peek()
    {
        if(top>=0) cout<<"Top elememt is: "<<arr[top]<<endl;
        else cout<<"Stack is empty";
    }
};
int main()
{
    /*Stack st(5);

    st.push(10);
    st.push(15);
    st.push(20);

    st.peek();
    st.pop();
    return 0;*/

    stack<int> st;
    st.push(2);
    st.push(30);
    st.pop();
    cout<<st.top();
}