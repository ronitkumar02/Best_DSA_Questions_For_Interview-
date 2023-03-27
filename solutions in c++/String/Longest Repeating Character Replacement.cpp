#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int characterReplacement(string s, int k) {
    int window_start=0,max_len=0,max_cnt=0;
    vector<int> char_count(256,0);
    for(int i=0;i<s.size();i++){
        char_count[s[i]]+=1;
        max_cnt=max(max_cnt,char_count[s[i]]);
        if((i-window_start+1)>max_cnt+k){
            char_count[s[window_start]]-=1;
            window_start+=1;
        }
        max_len=max(max_len,i-window_start+1);
    }
    return max_len;
}

int main(){
    int k;cin>>k;
    string s;cin>>s;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}