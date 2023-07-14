#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
ll int merge(vector<ll> arr,ll temp[],int left,int mid,int right){
    int i=left,j=mid,k=left;
    int inv_count=0;
    while((i<=mid - 1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++]=arr[i++];
        }
        else {
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return inv_count;
}
ll int _mergeSort(vector<ll> arr,ll temp[],int left,int right){
    int mid,inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count+=(_mergeSort(arr,temp,left,mid)); 
        inv_count+=(_mergeSort(arr,temp,mid+1,right));
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

ll int mergeSort(vector<ll> arr,int n){
    ll temp[n];
    return _mergeSort(arr,temp,0,n-1);
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    cout<<mergeSort(a,n);
    return 0;
}
