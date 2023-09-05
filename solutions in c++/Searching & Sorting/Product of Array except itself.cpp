#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

vi find_product(vi &a){
    int n=a.size();
    vi pre(n),suf(n),pro(n);
    pre[0]=1;
    suf[n-1]=1;
    rep(i,1,n) pre[i]=pre[i-1]*a[i-1];
    for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]*a[i+1];
    rep(i,0,n) pro[i]=pre[i]*suf[i];
    return pro;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    vi product=find_product(a);
    rep(i,0,n) cout<<product[i]<<" ";
    return 0;
}