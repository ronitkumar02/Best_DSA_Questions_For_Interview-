#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string smallestWindow(string s,string p){
    vi m(256,0);
    int ans=INT_MAX;
    int st=0;
    int cnt=0;
    rep(i,0,p.size()){
        if(m[p[i]]==0){ 
            cnt++;
        }
        m[p[i]]++;
    }
    int i=0,j=0;
    while(j<s.size()){
        m[s[j]]--;
        if(m[s[j]]==0){
            cnt--;
        }
        if(cnt==0){
            while(cnt==0){
                if(ans>j-i+1){
                    ans=j-i+1;
                    st=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0){
                    cnt++;
                }
                i++;
            }
        }
        j++;
    }
    if(ans!=INT_MAX){
        return s.substr(st,ans);
    }
    else
    return "-1";
}

int main(){
    string s,p;
    cin>>s>>p;
    cout<<smallestWindow(s,p);
    return 0;
}