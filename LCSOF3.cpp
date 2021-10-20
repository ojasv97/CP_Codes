#include<bits/stdc++.h>
using namespace std;
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1][n2][n3];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                if(i==0 || j==0 || k==0){
                    dp[i][j][k]=0;
                }
                else if(A[i-1]==B[j-1] && A[i-1]==C[k-1] && C[k-1]==B[j-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                    cout<<dp[i][j][k];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                cout<<dp[i][j][k]<<" ";
            }
        }
    }
    return dp[n1][n2][n3];
}
int main(){
    string A = "geeksforgeeks";
    string B = "geeksfor";
    string C = "geeks";
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    int ans = LCSof3(A,B,C,n1,n2,n3);
    cout<<ans;
    return 0;
}