#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

//The Time Complexity: O(N*logN)
bool isAnagram1(string s,string t)
{
    if(s.size()!=t.size())
        return 0;
    sort(all(s));
    sort(all(t));
    return s==t;
}
//The Time Complexity: O(N)
bool isAnagram(string s, string t) {
    if(s.size()!=t.size())
    return 0;

    vi cnt(256,0);
    for(int i=0;i<s.length();i++)
    {
        cnt[s[i]]++;
        cnt[t[i]]--;
    }
    rep(i,0,256){
        if(cnt[i])
        return false;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    if(isAnagram(s,t))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}