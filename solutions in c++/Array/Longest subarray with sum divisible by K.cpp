#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
 
int max_lenght(vi a,int n,int k){
    vi mod_arr(n);
    int mx=0;
    int cur_sum=0;
    unordered_map<int,int> m;
    rep(i,0,n){
        cur_sum+=a[i];
        mod_arr[i]=((cur_sum%k)+k)%k;
        if(mod_arr[i]==0)
        {
            mx=i+1;
        }
        else if(m.find(mod_arr[i])==m.end())
        {
            m[mod_arr[i]]=i;
        }
        else{
            mx=max(mx,i-m[mod_arr[i]]);
        }
    }
    return mx;
}

int main(){
    int n,k;cin>>n>>k;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<max_lenght(a,n,k);
    return 0;
}