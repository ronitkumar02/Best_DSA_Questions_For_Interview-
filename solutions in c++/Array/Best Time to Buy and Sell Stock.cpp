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
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int min=a[0],ans=0;
    rep(i,1,n)
    {
        if(ans<a[i]-min)
        {
            ans=a[i]-min;
        }
        if(min>a[i])
        {
            min=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}