#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)


// Time Complexity: O((N+M) * log(N+M))
// Auxiliary Space: O(1)
void merge1(vi &a,vi &b,int n,int m){
    int i = 0, j = 0, k = n - 1;

    while (i <= k && j < m) {
        if (a[i] < b[j])
            i++;
        else {
            swap(b[j++], a[k--]);
        }
    }
    sort(all(a));
    sort(all(b));
    cout<<endl;
}
//Time Complexity: O(max(N * logN, M * logM))
// Auxiliary Space: O(1)
void rotate(vi &a, int n, int idx)
{
    int i;
    for (i = 0; i < idx / 2; i++)
        swap(a[i], a[idx - 1 - i]);
    for (i = idx; i < (n + idx) / 2; i++)
        swap(a[i], a[n - 1 - (i - idx)]);
    for (i = 0; i < n / 2; i++)
        swap(a[i], a[n - 1 - i]);
}
  
void sol(vi &a, vi &b, int n, int m)
{
    int l = 0, h = n - 1, idx = 0;
    while (l <= h) {
        int c1 = (l + h) / 2;
        int c2 = n - c1 - 1;
        int l1 = a[c1];
        int l2 = b[c2 - 1];
        int r1 = c1 == n - 1 ? INT_MAX : a[c1 + 1];
        int r2 = c2 == m ? INT_MAX : b[c2];

        if (l1 > r2) {
            h = c1 - 1;
            if (h == -1)
                idx = 0;
        }
        else if (l2 > r1) {
            l = c1 + 1;
            if (l == n - 1)
                idx = n;
        }
        else {
            idx = c1 + 1;
            break;
        }
    }
  
    for (int i = idx; i < n; i++)
        swap(a[i], b[i - idx]);
  
    sort(all(a));
    sort(all(b));
}
  
void merge2(vi &a,vi &b, int n, int m)
{
    if (n > m) {
        sol(b, a, m, n);
        rotate(a, n, n - m);
  
        for (int i = 0; i < m; i++)
            swap(b[i], a[i]);
    }
    else {
        sol(a, b, n, m);
    }
}
//--------------------------------------------------------------------------------
//Merge two sorted arrays with O(1) extra space using Insertion Sort with Simultaneous Merge:
  
void merge3(vi &a,vi &b, int n, int m)
{
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            swap(a[i], b[j]);
            i++;
            if (j < m - 1 && b[j + 1] < b[j]) {
                int temp = b[j];
                int tempj = j + 1;
                while (b[tempj] < temp && tempj < m) {
                    b[tempj - 1] = b[tempj];
                    tempj++;
                }
                b[tempj - 1] = temp;
            }
        }
    }
}
//gap method
void merge4(vi &a,vi &b,int n,int m){
    int mid=(n+m)/2+(n+m)%2;
    int left,right;
    while(mid>1){
        left=0,right=mid;
        while(right<m+n){
            if(left<n and right>=n){
                if(a[left]>b[right]){
                    int temp=a[left];
                    a[left]=b[right];
                    b[right]=a[left];
                }
            }
            else if(left>=n){
                if(b[left]>b[right]){
                    int temp=a[left];
                    a[left]=b[right];
                    b[right]=a[left];
                }
            }
            else{
                if(a[left]>a[right]){
                    int temp=a[left];
                    a[left]=b[right];
                    b[right]=a[left];

                }
            }
            left++;
            right++;
        }
        cout<<mid<<" ";
        mid=(mid/2)+mid%2;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vi a(n),b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    merge3(a,b,n,m);
    rep(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
    rep(i,0,m) cout<<b[i]<<" ";
    return 0;
}