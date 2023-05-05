#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int Count(vi &a,int n,int sum){
    int count=0;
    rep(i,0,n-2){
        int j=i+1,k=n-1;
        while (j<k)
        {
            if ((a[i]+a[j]+a[k])>=sum)
                k--;
                else
                {
                    count+=(k-j);
                    j++;
                }
        }
    }
    return count;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int sum;cin>>sum;
    cout<<Count(a,n,sum);
    return 0;
}