#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &v, int woodreq, int mid,int n)
{
    int wood=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>mid)
        {
            wood+=v[i]-mid;
        }
        if(wood>=woodreq)
            return true;
    }
    return false;
    
}
int main()
{
    vector<int>v;
    int n, woodreq;
    cin>>n>>woodreq;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int> v1=v;
    sort(v1.begin(),v1.end());
    int s=0;
    int e=v1[n-1];
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<e)
    {
        if(isPossible(v,woodreq,mid,n))
        {
            ans=mid;
            s=mid+1;
        }
        else   
            e=mid-1;
        mid=s+(e-s)/2;
    }
    cout<<ans<<endl;
    return 0;
}