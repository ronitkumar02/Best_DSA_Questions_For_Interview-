#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

bool compare(pair<int,int> pl,pair<int,int> p2)
{
    return pl.first<p2.first;
}

vector<pii> merge(vector<pii> &a,int n)
{
    sort(all(a),compare);
    stack<pii> s;
    vector<pii> ans;
    s.push(a[0]);
    for(int i=1;i<n;i++)
    {
        pii top=s.top();
        if(top.second<a[i].first)
            s.push(a[i]);
        else if(top.second<a[i].second){
            top.second=a[i].second;
            s.pop();
            s.push(top);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    sort(all(ans),compare);
    return ans;
}

int main(){
    int n;cin>>n;
    vector<pii> a(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        a[i].first=x;
        a[i].second=y;
    }
    vector<pii> ans=merge(a,n);
    rep(i,0,ans.size())
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}