#include<bits/stdc++.h>
using namespace std;

int maxsubarray(vector<int> arr,int k)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    int start=0,end=k-1;
    int temp=sum;
    while(end!=arr.size())
    {
        sum-=arr[start];
        sum+=arr[end];
        if(sum>temp)
        {
            temp=sum;
        }
        start++;
        end++;
    }
    return temp;
}

int main()
{
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxsubarray(arr,k);
    return 0;
}