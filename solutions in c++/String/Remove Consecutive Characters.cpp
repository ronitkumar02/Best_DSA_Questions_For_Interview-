#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string s)
{
    string str="";
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            str+=s[i];
        }
    }
    str+=s[s.size()-1];
    return str;
}

int main()
{
    string s;
    cin>>s;
    cout<<removeConsecutiveCharacter(s);
    return 0;
}