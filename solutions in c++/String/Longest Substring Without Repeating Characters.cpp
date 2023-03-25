#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int substring(string s){
    vector<int> dict(256,-1);
    int maxLen=0,j=-1;
    rep(i,0,s.size()){
        if(dict[s[i]]>j){
            j=dict[s[i]];
        }
        dict[s[i]]=i;
        maxLen=max(maxLen,i-j);
    }
    return maxLen;
}

int main(){
    string s;
    cin>>s;
    cout<<substring(s);
    return 0;
}