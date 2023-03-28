#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
int x=31;
int N=1e5+7,M=1e9+7;
vector<long  long> power(N);
void index(string s,string p){
    int S=s.size(),P=p.size();
    vector<long long> h(S+1,0);
    power[0]=1;
    rep(i,1,N){
        power[i]=(power[i-1]*x)%M;
    }
    rep(i,0,S){
        h[i+1]=(h[i]+(s[i]-'a'+1)*power[i])%M;
    }
    long long h_p=0;
    rep(i,0,P){
        h_p=(h_p+(s[i]-'a'+1)*power[i])%M;
    }
    for(int i=0;i+P-1<S;i++){
        long long cur_h=(h[i+P]-h[i]+M)%M;
        if(cur_h==(h_p*power[i])%M){
            cout<<i<<" ";
        }
    }
}

int main(){
    string s,p;
    cin>>s>>p;
    index(s,p);
    return 0;
}