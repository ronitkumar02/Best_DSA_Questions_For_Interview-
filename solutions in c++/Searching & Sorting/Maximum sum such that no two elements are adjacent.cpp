#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
//Normal recursion function
//Time Complexity: O(2n)
//Auxiliary Space: O(n)
int findMaxSum1(vi &a,int &n,int i){
    if(i>=n){
        return 0;
    }
    int opt1=a[i]+findMaxSum1(a,n,i+2);
    int opt2=findMaxSum1(a,n,i+1);
    return max(opt1,opt2);
}
//Using Dp
// Time Complexity: O(n)
// Auxiliary Space: O(n)
int findMaxSum2(vector<int> &arr, int n)
{
    int dp[n][2];
    if (n == 1) {
        return arr[0];
    }

    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][1],
                       dp[i - 1][0]);
    }
   
    return max(dp[n - 1][0], dp[n - 1][1]);
}
//Space Optimized Approach
// Time Complexity: O(n)
// Auxiliary Space: O(1).
int findMaxSum3(vector<int> &arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;
 
    for (i = 1; i < n; i++) {
        // Current max excluding i
        excl_new = max(incl, excl);
 
        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
    }
 
    // Return max of incl and excl
    return max(incl, excl);
}
int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    cout<<findMaxSum3(a,n);
    return 0;
}