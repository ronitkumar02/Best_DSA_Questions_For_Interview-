#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

vi productExceptSelf(vi & nums,int n) {
    int mul=1;
    bool flag=0;
    int count=0;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=0)
        mul*=nums[i];
        else{
            flag=1;
            count++;
            idx=i;
            if(count>1)
            {
                break;
            }
        }
    }
    if(flag && count>1)
    {
        for(int i=0;i<n;i++)
            nums[i]=0;
    }
    else if(flag && count ==1)
    {
        for(int i=0;i<n;i++)
        {
            if(i==idx)
                nums[i]=mul;
            else
                nums[i]=0;
        }
    }
    else{
        for(int i=0;i<n;i++)
            nums[i]=(mul/nums[i]);
    }
    return nums;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    vi ans=productExceptSelf(a,n);
    rep(i,0,n)cout<<ans[i]<<" ";
    return 0;
}