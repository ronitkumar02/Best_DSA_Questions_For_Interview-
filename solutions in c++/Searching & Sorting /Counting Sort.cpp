#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

const int RANGE=255;

void countSort(string &str)
{
    vector<char> output(str.size());
    vi count(RANGE,0);
    for (auto i : str)
        ++count[i];
    for (int i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (int i = 0; i<str.size(); ++i) {
        output[--count[str[i]]] = str[i];
    }
    for (int i = 0;i<str.size(); ++i)
        str[i] = output[i];
}

// Driver code
int main()
{
    string str;
    cin>>str;
    countSort(str);
    cout << "Sorted character array is " << str;
    return 0;
}