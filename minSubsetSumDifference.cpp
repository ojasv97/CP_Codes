#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a{2,5,3,20,6};
    int s=0;
    int t=0;
    for(auto x:a){
        s+=x;
    }
    t=s;
    s= s/2;
    vector<vector<int>> dp(a.size()+1,vector<int>(s+1,-1));
    for(int i=0;i<=s;i++){dp[0][i]=0;}
    for(int i=0;i<=a.size();i++){dp[i][0]=1;}
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=s;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int j=s;j>=0;j--){
        if(dp[a.size()][j]==1){
            cout<<t-2*j<<endl;
            break;
        }
    }
    return 0;
}