#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string LongestSubstring(string s){
    int n=s.size();
    int table[n][n];
    memset(table,0,sizeof(table));
    int mx_len=1;
    rep(i,0,n){
        table[i][i]=1;
    }
    int st=0;
    rep(i,0,n-1){
        if(s[i]==s[i+1]){
            table[i][i+1]=1;
            st=i;
            mx_len=2;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
        int j=i+k-1;
        if(table[i+1][j-1] && s[i]==s[j]){
            table[i][j]=1;
            if(k>mx_len)
            {
                st=i;
                mx_len=k;
            }
        }
    }
    }
    return s.substr(st,mx_len);
}

int main(){
    string s;cin>>s;
    cout<<LongestSubstring(s);
    return 0; 
}