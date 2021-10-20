#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int fun(int j, vector<int>&a, int sum, int i,int ws,vector<vector<int>>&dp){
    if(i==-1){
        return sum;
    }
    if(j==0){
        return dp[i][j]=fun(1,a,sum,i-1,ws,dp);
    }
    return dp[i][j]=max(fun((j+1)%ws,a,sum+a[i],i-1,ws,dp),fun(1,a,sum,i-1,ws,dp));
}
int main(){
    vector<int> a{4,5,6,3,2,3,7,8,9,2};
    int ws = 6;
    ws++;
    vector<vector<int>>dp(a.size(),vector<int>(ws,-1));
    int sum = 0;
    int ans = fun(1,a,sum,a.size()-1,ws,dp);
    cout<<ans;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<ws;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}