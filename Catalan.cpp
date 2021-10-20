#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[i-j-1]*dp[j];
        }
    }
    for(auto x:dp){cout<<x<<" ";}
    cout<<endl;
    cout<<dp[n];
    return 0;
}