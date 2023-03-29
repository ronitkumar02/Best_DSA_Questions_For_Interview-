#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

//Upward Traversal
vi zigzagUpward(int n,vvi &matrix){
    vi ans;
    int row=0,col=0;
    while(row<n){
        int r=row;
        int c=col;
        while(r>=0 && c<n){
            ans.push_back(matrix[r][c]);
            r--;
            c++;
        }
        row++;
    }
    row=n-1;
    col=1;
    while(col<n){
        int r=row;
        int c=col;
        while(r>=0 && c<n){
            ans.push_back(matrix[r][c]);
            r--;
            c++;
        }
        col++;
    }
    return ans;
}

//downwardDiagonal
vi zigzagDownward(int n,vvi &matrix){
    vi ans;
    int row=0,col=0;
    while(col<n){
        int r=row;
        int c=col;
        while(r<n && c>=0){
            ans.push_back(matrix[r][c]);
            r++;
            c--;
        }
        col++;
    }
    col=n-1;
    row=1;
    while(row<n){
        int r=row;
        int c=col;
        while(r<n && c>=0){
            ans.push_back(matrix[r][c]);
            r++;
            c--;    
        }
        row++;
    }
    return ans;
}

//up and down Traversal
vi zigzagUpandDown(int n,vvi &matrix)
{
    vi ans;
    int row=0,col=0;
    bool up=true;
    while(row<n and col<n){
        if(up){
            while(row>0 and col<n-1){
                ans.push_back(matrix[row][col]);
                row--;
                col++;
            }
            ans.push_back(matrix[row][col]);
            if(col==n-1){
                row++;
            }
            else{
                col++;
            }
        }
        else{
            while(row<n-1 and col>0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
            ans.push_back(matrix[row][col]);
            if(row==n-1){
                col++;
            }
            else{
                row++;
            }
        }
        up=!up;
    }
    return ans;
}

//Spiral Traversal
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
    vi ans=zigzagUpward(n,matrix);
    rep(i,0,n*n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans=zigzagDownward(n,matrix);
    rep(i,0,n*n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans=zigzagUpandDown(n,matrix);
    rep(i,0,n*n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans=spiral(n,matrix);
    rep(i,0,n*n){
        cout<<ans[i]<<" ";
    }
    return 0;
}