#include<bits/stdc++.h>
using namespace std;
long long int solve(vector<long long int> &a){
    vector<int> c(a.size(),0);
    long long int temp;
    for(int i=0;i<a.size();i++){
        temp = a[i];
        while(temp!=0){
            c[i]++;
            temp = temp>>1;
        }
    }
    unordered_map<long long int,long long int> b;
    for(int i=0;i<c.size();i++){
        b[c[i]]++;
    }
    long long int count=0;
    for(auto x:b){
        if(x.second%2==0){
            count+=(x.second/2)*(x.second-1);
        }
        else{
            count+=(x.second)*((x.second-1)/2);
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long int ans = solve(a);
        cout<<ans<<endl;
    }
    return 0;
}