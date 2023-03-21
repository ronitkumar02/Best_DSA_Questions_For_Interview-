#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int NumberOfoperations(vi a){
    int n=a.size();
    int i=0,j=n-1;
    int ans=0;
    while(i<=j)
    {
        if(a[i]>a[j]){
            a[j-1]+=a[j];
            ans++;
            j--;
            continue;
        }
        else if(a[i]<a[j]){
            a[i+1]+=a[i];
            ans++;
            i++;
            continue;
        }
        i++;j--;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<NumberOfoperations(a);
    return 0;
}