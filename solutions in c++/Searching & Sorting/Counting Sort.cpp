#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

const int N=1e5+1;

void countSort(vi &a,int n){
    vi cnt(N,0);
    vi output(n);
    rep(i,0,n)
        cnt[a[i]]++;
    rep(i,1,N)
        cnt[i]+=cnt[i-1];
    rep(i,0,n){
        output[cnt[a[i]]-1]=a[i];
        --cnt[a[i]];
    }
    a=output;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    countSort(a,n);
    rep(i,0,n)cout<<a[i]<<" ";
    return 0;
}