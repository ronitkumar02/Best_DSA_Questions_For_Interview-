#include<bits/stdc++.h>
using namespace std;

pair<int,int> PairOfSum(vector<int> arr,int sum)
{
    pair<int,int> ans(-1,-1);
    int i;
    int n=arr.size();
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        break;
    }
    int l=(i+1)%n;
    int r=i;
    while(r!=l)
    {
        if((arr[l]+arr[r])==sum){
            ans.first=arr[l];
            ans.second=arr[r];
            return ans;
        }
        if((arr[l]+arr[r])<sum)  l=(l+1)%n;
        else r=(n+r-1)%n;
    }
    return ans;
}

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    pair<int,int> ans=PairOfSum(arr,sum);
    if(ans.first==-1)
    {
        cout<<"No solution";
    }
    else
    {
        cout<<ans.first<<" "<<ans.second;
    }
    return 0;
}