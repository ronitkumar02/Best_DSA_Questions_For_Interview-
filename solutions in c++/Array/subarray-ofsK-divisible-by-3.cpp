#include<bits/stdc++.h>
using namespace std;

vector<int> subarray(vector<int> arr,int k)
{
    vector<int> res;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    for(int i=k;i<arr.size();i++)
    {
        sum+=(arr[i]-arr[i-k]);
        if(sum%3==0)
        {
            for(int j=i-k+1;j<=i;j++)
            {
                res.push_back(arr[j]);
            }
            return res;
        }
    }
    res.push_back(-1);
    return res;
}

int main()
{
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> res=subarray(arr,k);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}