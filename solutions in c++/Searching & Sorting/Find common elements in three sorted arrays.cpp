#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

//Time Complexity: O(n1 + n2 + n3) Auxiliary Space: O(1)
vi Common1(vi &a,vi &b,vi &c){
    int n1=a.size();
    int n2=b.size();
    int n3=c.size();
    int i=0,j=0,k=0;
    int prev1,prev2,prev3;
    prev1=prev2=prev3=INT_MIN;
    vi ans;
    while(i<n1 && j<n2 && k<n3){
        while(a[i]==prev1 && i<n1){
            i++;
        }
        while(b[j]==prev2 && j<n2)
        {
            j++;
        }
        while(c[k]==prev3 && k<n3){
            k++;
        }
        if(a[i]==b[j] && b[j]==c[k]){

            ans.push_back(a[i]);
            prev1=a[i++];
            prev2=b[j++];
            prev3=c[k++];
        }
        else if(a[i]<b[j]){
            prev1=a[i++];
        }
        else if(b[j]<c[k]){
            prev2=b[j++];
        }
        else{
            prev3=c[k++];
        }
    }
    return ans;
}

// Using Binary Search
// Time complexity: O(n1(log(n2*n3)) Auxiliary complexity: O(1)
bool binary_search(vi &b,int key){
    int l=0,h=b.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(b[mid]==key){
            return true;
        }
        else if(b[mid]<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return false;
}
vi Common2(vi &a,vi &b,vi &c){
    vi ans;
    for(int j=0;j<a.size();j++){
        if(j!=0 && a[j]==a[j-1]){
            continue;
        }
        if(binary_search(b,a[j]) && binary_search(c,a[j])){
            ans.push_back(a[j]);
        }
    }   
    return ans;
}

int main(){
    int x,y,z;
    cin>>x;
    vi a(x);
    rep(i,0,x)
        cin>>a[i];
    cin>>y;
    vi b(y);
    rep(i,0,y)
        cin>>b[i];
    cin>>z;
    vi c(z);
    rep(i,0,z)
        cin>>c[i];
    vi ans=Common2(a,b,c);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    return 0;
}