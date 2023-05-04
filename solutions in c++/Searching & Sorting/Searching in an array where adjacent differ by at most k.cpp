#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int search(vi a,int x,int k){
    int i=0;
    while(i<a.size()){
        if(a[i]==x){
            return i;
        }
        i+=max(1,abs(a[i]-x)/k);
    }
    return -1;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int k;cin>>k;
    int x;cin>>x;
    cout<<search(a,x,k);
    return 0;
}