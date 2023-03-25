#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string Prefix(vector<string> s){
    sort(all(s));
    string ans="";
    int n=s.size();
    rep(i,0,s[0].size()){
        if(s[0][i]==s[n-1][i]){
            ans+=s[0][i];
        }
        else{
            break;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<string> st(n);
    rep(i,0,n){
        cin>>st[i];
    }
    cout<<Prefix(st);
    return 0;
}