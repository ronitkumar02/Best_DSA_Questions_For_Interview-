#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

pii Find(vi a,int n,int diff){
    sort(all(a));
    int i=0,j=1;
    while(i<n && j<n){
        if(i!=j && ((a[j]-a[i])==diff || (a[i]-a[j])==n))
            return make_pair(a[i],a[j]);
        else if (a[j]-a[i]<abs(n))
            j++;
        else
            i++;
    }
    return make_pair(-1,-1);
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int diff;cin>>diff;
    pii ans=Find(a,n,diff);
    if(ans.first==-1)
        cout<<"No such pair";
    else
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}