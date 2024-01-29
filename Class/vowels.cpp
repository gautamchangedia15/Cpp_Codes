#include<iostream>
#include<string.h>
using namespace std;

class vowels
{
   // private: 
    public:
    int l=0,v=0;
    string word;
    void getData();
    int setData();
};
void vowels::getData()
{
    cout<<"Enter a word:";
    cin>>word;
}
int vowels::setData()
{
    l=word.size();
    for(int i=0;i<l;i++)
    {
        if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='s')
        v++;
    }
    return v;
}
int main()
{
    vowels a;
    a.getData();
    cout<<"No of vowels: "<<a.setData();
    return 0;
}