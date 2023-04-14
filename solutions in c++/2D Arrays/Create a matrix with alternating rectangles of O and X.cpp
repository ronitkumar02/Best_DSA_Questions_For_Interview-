#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void fill(int n,int m)
{
    int k=0,l=0;
    int r=n,c=m;
    char a[n][m];
    char x='X';
    memset(a,'0',sizeof(a));
    while(k<n && l<m){
        for(int i=l;i<m;i++){
            a[k][i]=x;
        }
        k++;
        for(int i=k;i<n;i++){
            a[i][m-1]=x;
        }
        m--;
        if(k<n){
            for(int i=m-1;i>=l;i--){
                a[n-1][i]=x;
            }
            n--;
        }
        if(l<m){
            for(int i=n-1;i>=k;i--){
                a[i][l]=x;
            }
            l++;
        }
        x=(x=='O')?'X':'O';
    }
    rep(i,0,r){
        rep(j,0,c){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    fill(n,m);
    return 0;
}