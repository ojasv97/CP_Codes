#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        vector<int> arr(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx=max(mx,arr[i]);
        }
        sort(arr.begin(),arr.end());
        int val = arr[0]+arr[1];
        if(mx<=d){
            cout<<"YES"<<endl;
        }
        else{
            if(val<=d){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}