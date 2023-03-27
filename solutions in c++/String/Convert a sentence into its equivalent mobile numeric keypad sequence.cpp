#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

string str[]= { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };

string numeric_keypad(string s){
    string ans="";
    rep(i,0,s.length()){
        if(s[i]==' '){
            ans+='0';
        }
        else{
            ans+=str[s[i]-'A'];
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout<<numeric_keypad(s);
    return 0;
}
