#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int product(vi &a,int n)
{
    int mx=1,mn=1;
    int ans=INT_MIN;
    rep(i,0,n){
        if(a[i]<0)
        {
            swap(mn,mx);
        }
        mx=max(mx*a[i],a[i]);
        mn=min(mn*a[i],a[i]);
        ans=max(mx,ans);
    }
    return ans;
}

int main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<product(a,n);
    return 0;
}