#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

vvi sum(vi &a,int n)
{
    sort(all(a));
    set<vector<int>> s;
    vvi ans;
    rep(i,0,n){
        int low=i+1,high=n-1;
        while(low<high){
            if(a[i]+a[low]+a[high]>0) 
            {high--;
            }
            else if(a[i]+a[low]+a[high]<0){
                 low++;
            }
            else{
                s.insert({a[i],a[low],a[high]});
                low++;high--;
            }
        }
    }
    for(auto &i: s)
    ans.push_back(i);
    return ans;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    vvi ans=sum(a,n);
    for(auto i:ans){
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}