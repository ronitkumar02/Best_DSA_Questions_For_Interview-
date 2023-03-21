#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    int a,b;cin>>a>>b;
    vi arr(b-a+1,0);
    rep(i,a,b+1){
        if(i%2==0||i%5==0)
        {
            arr[i-a]=1;
        }
    }
    rep(i,0,arr.size()){
        if(arr[i]==1){
            cout<<i+a<<" ";
        }
    }
    return 0;
}