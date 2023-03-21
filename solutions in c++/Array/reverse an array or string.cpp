#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> arr)
{
    int start=0,end=arr.size()-1;
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    return arr;
}

string reverseString(string &s)
{
    int start=0,end=s.size()-1;
    while(start<end)
    {
        int temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
    return s;
}
int main()
{
    int t;cin>>t;
    if(t==1){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arr=reverse(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
    }
    else
    {
        string s;
        cin>>s;
        cout<<reverseString(s)<<endl;
        return 0;
    }
}