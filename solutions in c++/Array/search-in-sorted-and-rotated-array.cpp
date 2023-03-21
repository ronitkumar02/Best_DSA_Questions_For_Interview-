#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr,int key,int left,int right)
{
    if(left>right)
    {
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    if(arr[left]<=arr[mid])
    {
        if(key>=arr[left] && key<=arr[mid])
        {
            return search(arr,key,left,mid-1);
        }
        return search(arr,key,mid+1,right);
    }
    if(key>=arr[mid] && key<=arr[right])
    {
        return search(arr,key,mid+1,right);
    }
    return search(arr,key,left,mid-1);
}

int main()
{
    int n;cin>>n;
    vector<int>  arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;cin>>key;
    int ans=search(arr,key,0,n-1);
    if(ans==-1)
    {
        cout<<"Not found";
    }
    else
    {
        cout<<ans+1;
    }
    return 0;
}