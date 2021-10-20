#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101][101];
int main(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int mx = 0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    if(mat[i-1][j-1]==mat[k-1][l-1] && (i) ){
                        int a = min(dp[i-1][j][k][l],min(dp[i][j-1][k][l],dp[i-1][j-1][k][l]));
                        int b = min(dp[i][j][k-1][l],min(dp[i][j][k][l-1],dp[i][j][k-1][l-1]));
                        dp[i][j][k][l] = 1+min(a,b);
                        if(abs(i-k)>=dp[i][j][k][l] || abs(j-l)>=dp[i][j][k][l]){
                            mx = max(mx,dp[i][j][k][l]);
                        }
                    }
                    else{
                        dp[i][j][k][l] = 0;
                    }
                }
            }
        }
    }
    cout<<mx*mx<<endl;
    return 0;
}