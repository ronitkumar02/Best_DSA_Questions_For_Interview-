#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    rep(i,0,strs.size()){
        string str=strs[i];
        sort(all(str));
        mp[str].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto & j: mp)
    {
        vector<string> temp;
        for(int i=0;i<(j.second).size();i++){
            temp.push_back(j.second[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    vector<vector<string>> ans=groupAnagrams(strs);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}