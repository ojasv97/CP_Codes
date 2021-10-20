#include<bits/stdc++.h>
using namespace std;
int rec(stack<int>&s,int k){
    if(k==0){return s.top();}
    int temp = s.top();
    s.pop();
    int y = rec(s,k-1);
    return y;
}
int main(){
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(5);
    a.push(6);
    a.push(3);
    a.push(9);
    a.push(0);
    int ans = rec(a,a.size()/2);
    cout<<ans;
    return 0;
}