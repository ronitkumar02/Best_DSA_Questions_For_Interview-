#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate2(vector<int> nums)
{
    if(!nums.size())
        return 0;
    unordered_set<int> st;
    int j=0;
    for(auto i: nums)
    {
        st.insert(i);
        j++;
        if(st.size()!=j)
        return true;
    }
    return false;
}
int main()
{
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<containsDuplicate2(nums);
    return 0;
}