#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

struct triplet{
    int l,r,idx;
};

int block;
bool compare(triplet x,triplet y){
    if(x.l/block!=y.l/block){
        return x.l/block<y.l/block;
    }
    return x.r<y.r;
}

vi queryResult(vi a,int n,vector<triplet> query,int q){
    block=(int)sqrtl(n);
    sort(all(query),compare);
    int st=0,en=0;
    int sum=0;
    vi ans(q);
    rep(i,0,q){
        int l=query[i].l,r=query[i].r;
        while(st<l){
            sum-=a[st];
            st++;
        }
        while(st>l){
            sum+=a[st-1];
            st--;
        }
        while(en<=r){
            sum+=a[en];
            en++;
        }
        while(en>r+1){
            sum-=a[en-1];
            en--;
        }
        ans[query[i].idx]=sum;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int q;cin>>q;
    vector<triplet> query(q);
    rep(i,0,q){
        int x,y;
        cin>>x>>y;
        query[i]={x,y,i};
    }
    vi ans=queryResult(a,n,query,q);
    rep(i,0,q)cout<<ans[i]<<" ";
    return 0;
}