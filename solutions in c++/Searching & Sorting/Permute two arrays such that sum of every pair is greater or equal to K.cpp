#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string isPossible(vi &a,vi &b,int k){
    sort(all(a));
    sort(all(b),greater<int>());
    rep(i,0,a.size()){
        if((a[i]+b[i])<k){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    int n;cin>>n;
    vi a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    int k;
    cin>>k;
    cout<<isPossible(a,b,k);
    return 0;
}