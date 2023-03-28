#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int dp[1000][1000];
string s;
int n;

int countPS(int i,int j){
    if(i>j){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==j){
        return dp[i][j]=1;
    }
    else if(s[i]==s[j])
    return dp[i][j]=countPS(i+1,j)+countPS(i,j-1)+1;
    else
    return dp[i][j]=countPS(i+1,j)+countPS(i,j-1)-countPS(i+1,j-1);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>s;
    n=s.size();
    cout<<countPS(0,n-1);
    return 0;  
}