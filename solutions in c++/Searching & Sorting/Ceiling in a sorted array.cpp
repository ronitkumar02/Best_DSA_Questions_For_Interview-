#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

int ceiling(vi &a,int n,int x){
    int low=0,high=n-1;
    if(x<=a[low])
       return a[low];
    if (x>a[high])
        return -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x)
            return a[mid];
        else if(a[mid]<x){
            if(mid+1<=high && x<=a[mid+1])
                return a[mid+1];
            else
                low=mid+1;
        }
        else{
            if(mid-1>=low && x>a[mid-1])
            return a[mid];
            else
            high=mid-1;
        }
    }
    return -1;
}

int flooring(vi &a,int n,int x){
    int low=0,high=n-1;
    if(x<=a[low])
       return -1;
    if (x>a[high])
        return a[high];
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x)
            return a[mid];
        else if(a[mid]<x){
            if(mid+1<=high && x>=a[mid+1])
                return a[mid];
            else
                low=mid+1;
        }
        else{
            if(mid-1>=low && x<a[mid-1])
            return a[mid-1];
            else
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int x;cin>>x;
    pii ans;
    ans.first=ceiling(a,n,x);
    ans.second=flooring(a,n,x);
    if(ans.first==-1)
        cout<<"Ceiling does not exists\n";
    else
        cout<<ans.first<<" "<<ans.second;
    return 0;
}