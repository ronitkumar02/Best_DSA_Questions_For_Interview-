#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void find(vi &arr,int n)
{
    rep(i,0,n){
        arr[arr[i]%n]+=n;
    }
    rep(i,0,n){
        if(arr[i]/n>1){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;cin>>n;
    vi arr(n);
    rep(i,0,n) cin>>arr[i];
    find(arr,n);
    return 0;
}