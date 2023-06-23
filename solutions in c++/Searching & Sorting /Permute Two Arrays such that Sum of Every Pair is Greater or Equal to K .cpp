#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string isgreater(vi &a,vi &b,int n,int k){
    sort(all(a));
    sort(all(b),greater<int>());
    rep(i,0,n){
        if(a[i]+b[i]<k)
            return "NO";
    }
    return "YES";
}
int main(){
    int n,k;
    cin>>n>>k;
    vi a(n),b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    string ans=isgreater(a,b,n,k);
    cout<<ans;
    return 0;
}