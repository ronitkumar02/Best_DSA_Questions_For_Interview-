#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vvi  vector<vector<int>>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)

//Without using stacks
bool isValid(string s){
    int j=-1;
    for(auto &i : s){
        if(i=='(' || i=='[' || i=='{'){
            s[++j]=i;
        }
        else if(i>=0 && ((s[j]=='(' && i==')') || (s[j]=='{' && i=='}') || (s[j]=='[' && i==']'))){
            j--;
        }
        else 
            return 0;
    }
    return j==-1;
}

// Using stacks 
bool isValid1(string s) {
    stack<int> st;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(st.empty()){
            st.push(c);
        }
        else if((c==')' and st.top()=='(')||(c=='}' and st.top()=='{')||(c==']' and st.top()=='['))
        {
            st.pop();
        }
        else
            st.push(c);
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;
    cout<<isValid1(s);
    return 0;
}