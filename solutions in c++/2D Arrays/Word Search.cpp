#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

bool helper(vector<vector<char>> &a,string word,int i,int j,int n,int m,int k){
    if(k>=word.size()) return true;
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='.' || word[k]!=a[i][j]) return false;
    if(word.size()==1 && word[k]==a[i][j]) return true;
    a[i][j]='.';
    int x[4]={0,0,-1,1};
    int y[4]={-1,1,0,0};
    bool temp=false;
    rep(z,0,4){
        temp = temp || helper(a,word,i+x[z],j+y[z],n,m,k+1);
    }
    a[i][j]=word[k];
    return temp;
}

bool search(vector<vector<char>> &a,string word){
    int n=a.size();
    if(n==0) return false;
    int m=a[0].size();
    if(word.size()==0) return false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(word[0]==a[i][j]){
                if(helper(a,word,i,j,n,m,0)) return true;   
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char> (m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    string word;
    cin>>word;
    cout<<search(a,word);
    return 0;
}