#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int findCommon(vvi &mat,int n,int m){
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
        cnt[mat[i][0]]++;

        for(int j=0;j<m;j++){
            if(mat[i][j]!=mat[i][j-1]){
                cnt[mat[i][j]]++;
            }
        }
    }
    for( auto i : cnt){
        if(i.second==n){
            return i.first;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi (n));
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    cout<<findCommon(a,n,m);
    return 0;
}