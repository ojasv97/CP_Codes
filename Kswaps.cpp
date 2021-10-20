#include<bits/stdc++.h>
using namespace std;
void solve(string str, int i, set<string> &s){
    if(i<str.length()){
        s.insert(str);
    }
    if(i==str.length()){
        return;
    }
    for(int j=0;j<str.length();j++){
        swap(str[i],str[j]);
        solve(str, i+1, s);
        swap(str[i],str[j]);
    }
}

int main(){
    string s = "ABSG";
    set<string> t;
    solve(s,0,t);
    for(auto it: t){
        cout<<it<<" ";
    }
    return 0;
}