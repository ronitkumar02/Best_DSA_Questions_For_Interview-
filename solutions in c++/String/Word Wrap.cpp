#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int dp[501][2001];

int rec(int i,int rem,vi &nums,int &k){
    if(i==nums.size()) return 0;
    if(dp[i][rem]!=-1) return dp[i][rem];
    int ans;
    if(nums[i]>rem){
        ans=(rem+1)*(rem+1)+rec(i+1,k-nums[i]-1,nums,k);
    }
    else{
        int choice1=(rem+1)*(rem+1)+rec(i+1,k-nums[i]-1,nums,k);
        int choice2=rec(i+1,rem-nums[i]-1,nums,k);
        ans=min(choice1,choice2);
    }
    dp[i][rem]=ans;
    return dp[i][rem];

}

int WordWrap(vi nums,int k){
    return rec(0,k,nums,k);
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vi nums(n);
    rep(i,0,n){
        cin>>nums[i];
    }
    int k;cin>>k;
    cout<<WordWrap(nums,k);
    return 0;
}