#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

//Using stacks
int waterTrapedusingstack(vi &a,int n)
{
    stack<int> st;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]<a[i])
        {
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}

//Using array
int waterTrapedusingarray(vi &a,int n)
{
    int res=0;
    rep(i,1,n-1){
        int l=a[i],r=a[i];
        rep(j,0,i)
        l=max(l,a[j]);
        rep(j,i+1,n)
        r=max(r,a[j]);

        res+=max(min(r,l)-a[i],0);
    }
    return res;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    cout<<waterTrapedusingarray(a,n)<<endl;
    cout<<waterTrapedusingstack(a,n)<<endl;
    return 0;
}