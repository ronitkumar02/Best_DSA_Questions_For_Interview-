#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void combination(vi a,vi data,int st,int en,int idx,int r){
    if(idx==r){
        rep(i,0,r){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=st;i<=en;i++){
        data[idx]=a[i];
        combination(a,data,i+1,en,idx+1,r);
    }   
}

int main(){
    int n,r;cin>>n>>r;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    vi data(r);
    combination(a,data,0,n-1,0,r);
    return 0;
}