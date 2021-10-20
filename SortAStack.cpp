#include<bits/stdc++.h>
using namespace std;

stack<int> stackSort(stack<int> &a, stack<int> &b){
    int n = a.size();
    cout<<"Hey"<<endl;
    while(n!=b.size()){
        cout<<a.size()<<" "<<b.size()<<endl;
        if(b.empty()){b.push(a.top());a.pop();}
        else if(a.top()>b.top()){
            int t = a.top();a.pop();
            int c = 0;
            while(!b.empty() && t>b.top()){
                a.push(b.top());b.pop();
                c++;
            }
            b.push(t);
            while(c--){
                b.push(a.top());a.pop();
            }
        }
        else if(a.top()<=b.top()){
            b.push(a.top());
            a.pop();
        }
    }
    return b;
}

int main(){
    stack<int> a;
    stack<int> b;
    a.push(2);
    a.push(3);
    a.push(1);
    a.push(3);
    a.push(4);
    b = stackSort(a,b);
    while(!b.empty()){
        cout<<b.top();
        b.pop();
    }
    return 0;
}
