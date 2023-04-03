#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

bool issafe(vector<vector<bool>> &land,int row,int col,vector<vector<bool>> &visit,int n,int m){
    return (row>=0)&&(row<n)&&(col>=0)&&(col<m)&&(land[row][col] && !visit[row][col]);
}

void dfs(vector<vector<bool>> &land,int n,int m,vector<vector<bool>> &visit){
    const int rowNbr[]={-1,-1,-1,0,0,1,1,1};
    const int colNbr[]={-1,0,1,-1,1,-1,0,1};
    visit[n][m]=1;
    for(int k=0;k<8;k++){
        if(issafe(land,n+rowNbr[k],m+colNbr[k],visit,n,m)){
            dfs(land,n+rowNbr[k],m+colNbr[k],visit);
        }
    }
}

int island(vector<vector<bool>> &land){
    int n=land.size(),m=land[0].size();
    vector<vector<bool>> visit(n,vector<bool> (m,0));
    int cnt=0;
    rep(i,0,n){
        rep(j,0,m){
            if(land[i][j] && !visit[i][j])
            {
                dfs(land,n,m,visit);
                ++cnt;
            }
        }
    }
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
        cout<<-1;
    vector<vector<bool>> land(n,vector<bool> (m,0));
    rep(i,0,n){
        rep(j,0,m){
            bool x;
            cin>>x;
            land[i][j]=x;
        }
    }
    cout<<island(land);
    return 0;
}