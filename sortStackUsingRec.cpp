#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&,int val);
void rec(stack<int> &a){
    if(a.size()==0){
        return;
    }
    int temp = a.top();
    a.pop();
    rec(a);
    insert(a,temp);
}
void insert(stack<int> &a, int val){
    if(a.size()==0 || a.top()<=val){
        a.push(val);
        return;
    }
    int temp = a.top();
    a.pop();
    insert(a,val);
    a.push(temp);
}
int main(){
    stack<int> a;
    a.push(5);
    a.push(1);
    a.push(3);
    a.push(2);
    a.push(9);
    a.push(7);
    int temp;
    rec(a);
    while(a.size()){
        temp = a.top();
        cout<<temp<<" ";
        a.pop();
    }
    return 0;
}