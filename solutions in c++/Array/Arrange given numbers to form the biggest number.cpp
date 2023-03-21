#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

bool compare(int x,int y){
    int xy=x,yx=y;
    int cntx=0,cnty=0;
    while(x>0){
        cntx++;
        x/=10;
    }
    while(y>0){
        cnty++;
        y/=10;
    }
    
}

void maxnumber(vi a,int n){
    sort(all(a),compare);
    for(auto i:a)
    {
        cout<<i;
    }
    return;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    maxnumber(a,n);   
    return 0;
}