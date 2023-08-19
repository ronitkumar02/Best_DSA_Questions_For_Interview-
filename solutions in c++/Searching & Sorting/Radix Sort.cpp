#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void countSort(vi &a,int n,int i){
    vi output(n);
    vi count(10,0);
    for(int j=0;j<n;j++)
        count[(a[j]/i)%10]++;
    
    for(int j=1;j<10;j++){
        count[j]+=count[j-1];
    }
    for(int j=n-1;j>=0;j--){
        output[count[(a[j] /i) % 10] - 1] = a[j];
        count[(a[j] /i) % 10]--;
    }
    a=output;
}

void radix(vi &a){
    int n = a.size();
    int mx=INT_MIN;
    for(int &i:a){
        mx=max(mx,i);
    }
    for(int i=1;mx/i>0;i*=10)
        countSort(a,n,i);
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    radix(a);
    rep(i,0,n)cout<<a[i]<<" ";
    return 0;
}