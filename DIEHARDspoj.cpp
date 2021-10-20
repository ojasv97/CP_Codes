#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001];
int solve(int h, int a, int t, int i){
    if(h<=0 || a<=0){
        return t-1;
    }
    if(dp[h][a]!=-1){
        return dp[h][a];
    }
    int x=0,f=0,w=0;
    if(i!=0){
        x = solve(h+3, a+2, t+1, 0);
    }
    if(i!=1){
        w = solve(h-5,a-10,t+1,1);
    }
    if(i!=2){
        f = solve(h-20,a+5,t+1,2);
    }
    return dp[h][a] = max(x,max(w,f));
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int a, h;
        cin>>h>>a;
        int t=0;
        t = solve(h,a,0,-1);
        cout<<dp[h][a]<<endl;
    }
    return 0;
}