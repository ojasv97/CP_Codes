#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long count_=0;
        vector<int> l(n+1,0);
        for(int j=0;j<n;j++){
            vector<int> r(n+1,0);
            for(int k=n-1;k>j;k--){
                count_= count_ + r[a[j]] * l[a[k]];
                r[a[k]]++;
            }
            l[a[j]]++;
        }
        cout<<count_<<endl;
    }
    return 0;
}