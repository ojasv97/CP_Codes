#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        bool flag = true;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<0<<endl;
        }
        else if(a[0]==1 || a[n-1]==n){
            cout<<1<<endl;
        }
        else if(a[0]==n && a[n-1]==1){
            cout<<3<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}