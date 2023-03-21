#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    int org=num;
    int rev=0;
    while(num)
    {
        rev=rev*10+num%10;
        num/=10;
    }
    return org==rev;
}

int findPalindromicSubarray(vector<int> arr,int k)
{
    int num=0;
    for(int i=0;i<k;i++)
    {
        num=num*10+arr[i];
    }
    if(isPalindrome(num))
    {
        return 0;
    }
    for(int j=k;j<arr.size();j++)
    {
        num=(num % (int)pow(10,k-1))*10+arr[j];
        if(isPalindrome(num))
        {
            return j-k+1;
        }
    }
    return -1;
}
int main()
{
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=findPalindromicSubarray(a,k);
    cout<<ans<<endl;
    return 0;
}