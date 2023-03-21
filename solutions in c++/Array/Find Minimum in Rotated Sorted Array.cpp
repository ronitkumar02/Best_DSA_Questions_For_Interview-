#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int s=0;
    int l=nums.size()-1;
    while(s<=l)
    {
        if(nums[s]<=nums[l])
        {
            return nums[s];
        }
        int mid=(l+s)/2;
        if(nums[mid]>=nums[s])
        {
            s=mid+1;
        }
        else{
            l=mid;
        }
    }
    return nums[s];
}

int main()
{
    int t;
    cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    cout<<findMin(arr);
    return 0;
}