#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p = gcd(100,n);
        cout<<100/p<<endl;
    }
    return 0;
}