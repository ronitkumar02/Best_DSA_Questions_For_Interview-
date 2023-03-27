#include<bits/stdc++.h>
using namespace std;

int minops(string a,string b)
{
    int m=a.size(),n=b.size();
    if(n!=m) return -1;
    vector<int> arr(256,0);
    for(int i=0;i<m;i++)
    {
        arr[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        arr[b[i]]--;
    }
    for(int i: arr)
    {
        if(i) return -1;
    }

    int res=0;
    for(int i=n-1,j=m-1;i>=0;)
    {
        while(i>=0 && a[i]!=b[j])
        {
            i--;
            res++;
        }
        if(i>=0)
        {
            i--;
            j--;
        }
    }
    return res;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<minops(a,b)<<endl;
    return 0;
}