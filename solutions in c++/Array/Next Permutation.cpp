#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int idx=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            idx=i;
            break;
        }
    }
    for(int i=n-1;i>=idx && (idx!=-1);i--){
        if(a[i]>a[idx])
        {
            swap(a[i],a[idx]);
            break;
        }
    }
    reverse(a.begin()+idx+1,a.end());
    rep(i,0,n)cout<<a[i]<<" ";
    return 0;
}