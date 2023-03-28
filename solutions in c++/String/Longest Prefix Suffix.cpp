#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int Longest(string s){
    int len=0;
    int st=0,en=1,mid=2;
    while(en<s.length()){
        if(s[st]==s[en]){
            st++;
            en++;
            len++;
        }
        else
        {
            st=0;
            en=mid;
            mid++;
            len=0;
        }
    }
	return len;
}

int main(){
    string s;
    cin>>s;
    cout<<Longest(s);
    return 0;
}