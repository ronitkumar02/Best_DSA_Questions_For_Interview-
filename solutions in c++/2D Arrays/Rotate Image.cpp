#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void rotate(vvi &matrix){
   int n=matrix.size();
   for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        swap(matrix[i][j],matrix[j][i]);
    }
   }
   for(int i=0;i<n;i++){
    reverse(matrix[i].begin(),matrix[i].end());
   }
}

int main(){
    int n;
    cin>>n;
    vvi matrix(n,vi (n));
    rep(i,0,n)
        rep(j,0,n)
            cin>>matrix[i][j];
    rotate(matrix);
    rep(i,0,n){
        rep(j,0,n)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}