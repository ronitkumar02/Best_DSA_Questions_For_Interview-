#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void badChar(string &t,vi &badchar){
    rep(i,0,badchar.size()){
        badchar[i]=-1;
    }
    rep(i,0,t.size()){
        badchar[(int)t[i]]=i;
    }
}

void search(string s,string t){
    int n=s.size();
    int m=t.size();
    vi badchar(256,0);
    badChar(t,badchar);
    int st=0;
    while(st<=(n-m)){
        int j=m-1;
        while(j>=0 && t[j]==s[st+j]){
            j--;
        }
        if(j<0){
            cout<<st<<" ";
            if(st+m<n){
                st+=m-badchar[s[st+m]];
            }
            else{
                st++;
            }
        }
        else{
            st+=max(1,j-badchar[s[st+j]]);
        }
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    search(s,t);
    return 0;
}