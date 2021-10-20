#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&,int);
void rev(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int temp = s.top();
    s.pop();
    rev(s);
    insert(s,temp);
}
void insert(stack<int> &s, int val){
    if(s.size()==0){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s,val);
    s.push(temp);
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
    rev(a);
    int temp;
    while(a.size()){
        temp = a.top();
        cout<<temp<<" ";
        a.pop();
    }
    return 0;
}