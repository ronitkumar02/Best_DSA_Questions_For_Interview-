#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)


vi spiral(int n,vvi &matrix){
    vi ans;
    int top=0,down=n-1,left=0,right=n-1;
    int dir=0;
    while(top<=down && left<=right)
    {
        if (dir==0)
        {
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
        }
        else if (dir==1)
        {
            for(int i=top;i<=down;i++)
                ans.push_back(matrix[i][right]);
            right--;
        }
        else if (dir==2)
        {
            for(int i=right;i>=left;i--)
                ans.push_back(matrix[down][i]);
            down--;
        }
        else if (dir==3)
        {
            for(int i=down;i>=top;i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vvi matrix(n,vi (n));
    rep(i,0,n)
        rep(j,0,n)
            cin>>matrix[i][j];
    vi ans=spiral(n,matrix);
    rep(i,0,n*n){
        cout<<ans[i]<<" ";
    }
}