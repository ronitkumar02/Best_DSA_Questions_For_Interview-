#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int maxArea(vector<int>& height) {
    int ans=INT_MIN;
    int l=0,r=height.size()-1;
    while(l<r)
    {
        int diff=r-l;
        if(height[l]>=height[r])
        {
            ans=max(ans,height[r]*diff);
            r--;
        }
        else{
            ans=max(ans,height[l]*diff);
            l++;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<maxArea(a);
    return 0;
}