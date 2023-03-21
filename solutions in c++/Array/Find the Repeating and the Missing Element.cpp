#include<bits/stdc++.h>
using namespace std;

int* findthenumber(int* arr,int n)
{
    int *v=new int[2];
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]<0)
        {
            v[0]=abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            v[1]=i+1;
            break;
        }
    }
    return v;
}
int main()
{
    int n;cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *v=findthenumber(arr,n);
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}