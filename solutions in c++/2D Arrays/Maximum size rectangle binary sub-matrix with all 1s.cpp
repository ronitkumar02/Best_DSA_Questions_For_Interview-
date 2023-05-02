#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int maxHist(vi row){
    stack<int> result;
    int top;
    int mx_area=0;
    int area=0;
    int i=0;
    while(i<row.size()){
        if( result.empty() || row[result.top()] <=row[i]){
            result.push(i++);
        }
        else{
            top=row[result.top()];
            result.pop();
            area=top*i;
            if(!result.empty()){
                area=top*(i-result.top()-1);
                mx_area=max(area,mx_area);
            }
        }
    }
    while(!result.empty()){
        top=row[result.top()];
        result.pop();
        area=top*i;
        if(!result.empty())
            area=top*(i-result.top()-1);
        mx_area=max(area,mx_area);
    }
    return mx_area;
}

int maxArea(vvi &a,int n,int m){
    int result=maxHist(a[0]);
    rep(i,1,n){
        rep(j,0,m){
            if(i!=0){
                a[i][j]+=a[i-1][j];
            }
        }
        result=max(result,maxHist(a[i]));
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi (m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    cout<<maxArea(a,n,m);
    return 0;
}