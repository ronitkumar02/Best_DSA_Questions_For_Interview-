#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), index = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    for(int i=n-1; i>=index && index != -1; i--){
        if(nums[i] > nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
}

int main(){
    int t;cin>>t;
    vi a(t);
    rep(i,0,t){
        cin>>a[i];
    }
    nextPermutation(a);
    rep(i,0,t){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

