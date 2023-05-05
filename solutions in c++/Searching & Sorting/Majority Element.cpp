#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

// Moore’s Voting Algorithm: Time Complexity: O(n) Auxiliary Space: O(1)
int isMajorityCandidate(vi &a,int n){
    int maj_index=0,cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[maj_index]){
            cnt++;
        }
        else{
            cnt--;
            if(cnt==0){
                maj_index=i;
                cnt=1;
            }
        }
    }
    return a[maj_index];
}

bool isMajority(vi &a,int n,int cand)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==cand){
            cnt++;
        }
    }
    return cnt>=n/2;
}

int Majority(vi &a,int n){
    int cand=isMajorityCandidate(a,n);
    if(isMajority(a,n,cand)){
        return cand;
    }
    else{
        return -1;
    }
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<Majority(a,n);
    return 0;
}