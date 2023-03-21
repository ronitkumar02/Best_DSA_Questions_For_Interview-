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
    int countx=0,county=0;
    while(x>0)
    {
        countx++;
        x/=10;
    }
    while(y>0)
    {
        county++;
        y/=10;
    }
    x=xy;
    y=yx;
    while(countx--)
        yx*=10;
    while(county--)
        xy*=10;
    yx+=x;
    xy+=y;
    return xy>yx;
}

void biggestNumber(vi &a){
    sort(all(a),compare);
    for(auto i:a){
        cout<<i;
    }
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    biggestNumber(a);
    return 0;
}