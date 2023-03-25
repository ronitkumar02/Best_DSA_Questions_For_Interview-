#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int expand(string s,int i,int j){
    int c=0;
    while(i>=0 && j<s.size() && s[i]==s[j]){
        c++;i--;j++;
    }
    return c;
}

int countSubstring(string s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        int odd=expand(s,i,i);
        cnt+=odd;
        int even=expand(s,i,i+1);
        cnt+=even;
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    cout<<countSubstring(s)<<endl;
    return 0;
}