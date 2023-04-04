#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void floodfillutil(vector<vector<char>> &mat,int x,int y,char prevc,char newc,int n,int m){
    if(x<0 || x>=m || y<0 || y>=n ){
        return;
    }
    if(mat[x][y]!=prevc){
        return;
    }
    mat[x][y]=newc;
    floodfillutil(mat,x-1,y,prevc,newc,n,m);
    floodfillutil(mat,x+1,y,prevc,newc,n,m);
    floodfillutil(mat,x,y-1,prevc,newc,n,m);
    floodfillutil(mat,x,y+1,prevc,newc,n,m);
}

void replace(vector<vector<char>> &mat,int n,int m){
    rep(i,0,n){
        rep(j,0,m){
            if(mat[i][j]=='O'){
                mat[i][j]='-';
            }
        }
    }
    rep(i,0,m)
        if(mat[i][0]=='-')
            floodfillutil(mat,i,0,'-','O',n,m);
    rep(i,0,m)
        if(mat[i][n-1]=='-')
            floodfillutil(mat,i,n-1,'-','O',n,m);
    rep(i,0,n)
        if(mat[0][i]=='-')
            floodfillutil(mat,0,i,'-','O',n,m);
    rep(i,0,m)
        if(mat[m-1][i]=='-')
            floodfillutil(mat,m-1,i,'-','O',n,m);

    rep(i,0,n){
        rep(j,0,m){
            if(mat[i][j]=='-')
            mat[i][j]='X';
        }
    }    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n,vector<char> (m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>mat[i][j];
        }
    }
    replace(mat,n,m);
    rep(i,0,n){
        rep(j,0,m){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}