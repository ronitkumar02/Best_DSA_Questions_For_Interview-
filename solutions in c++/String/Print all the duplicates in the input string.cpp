#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

vi duplicates(string s){
    vi cnt(256,0);
    rep(i,0,s.length()){
        cnt[s[i]]++;
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    vi ans=duplicates(s);
    rep(i,0,ans.size()){
        if(ans[i]>1){
            cout<<char(i)<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}
