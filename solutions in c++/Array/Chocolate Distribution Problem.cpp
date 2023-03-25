#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    sort(all(a));
    int m;cin>>m;
    int ans=INT_MAX;
    int st=0,en=m-1;
    while(en<n)
    {
        ans=min(ans,a[en]-a[st]);
        st++;en++;
    }
    cout<<ans<<endl;
    return 0;
}