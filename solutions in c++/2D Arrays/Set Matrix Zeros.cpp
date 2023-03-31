#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void SetMatrixZeros(vvi &matrix){
    int col0=1,row=matrix.size(),col=matrix[0].size();
    for(int i=0;i<row;i++){
        if(matrix[i][0]==0) col0=0;
        for(int j=1;j<col;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=matrix[0][j]=0;
            }
        }
    }
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=1;j--){
            if(matrix[i][0]==0 || matrix[0][j]==0)
            matrix[i][j]=0;
        }
        if(col0==0) matrix[i][0]=0; 
    }
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
    SetMatrixZeros(a);
    rep(i,0,n){
        rep(j,0,m){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}