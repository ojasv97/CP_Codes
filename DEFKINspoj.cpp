#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        vector<int> x(n+2,0);
        vector<int> y(n+2,0);
        for(int i=1;i<=n;i++){
            cin>>x[i];
            cin>>y[i];
        }
        x[n+1] = w+1;
        y[n+1] = h+1;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int my = 0;
        int mx = 0;
        for(int i=0;i<x.size()-1;i++){
            mx = max(x[i+1]-x[i],mx);
            my = max(y[i+1]-y[i],my);
        }
        cout<<(my-1)*(mx-1)<<endl;
    }
    return 0;
}