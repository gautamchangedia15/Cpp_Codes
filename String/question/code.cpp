//   Input:  Gautam is king
//   Output: matuaG si gnik


#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverseWords(vector<char> &s)
{
    string temp="";
    int start=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]== ' ') 
        {
            int end=i-1;
            while(start<=end)
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            start=i+1;
        }
    }
    int end=s.size()-1;
    while(start<=end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    

    return;
}
int main()
{
    string s;
    getline(cin,s);
    vector<char> v;
    for(int i=0;i<s.length();i++)
    {
        v.push_back(s[i]);
    }
    reverseWords(v);
    for(int i=0;i<s.length();i++)
    {
        cout<<v[i];
    }
    return 0;
}