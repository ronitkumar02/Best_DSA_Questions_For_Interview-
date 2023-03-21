#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> arr)
{
    int curr=0;
    int mx=0;
    for(auto i: arr)
    {
        curr+=i;
        mx=max(mx,curr);
        if(curr<0)
        {
            curr=0;
            continue;
        }
    }
    return mx;
}
int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxSubarray(arr);
    return 0;
}