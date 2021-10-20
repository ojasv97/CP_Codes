/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

int vis[100001];
int dfs(int par, int node, vector<pair<int,int>> adj[], int pathsum, int& cnt, vector<vector<int>> &mp){
    vis[node]=1;
    if(par!=-1 && pathsum%2==1 && mp[node][par]==0){
        cnt++;
        mp[node][par]=pathsum;
        mp[par][node]=pathsum;
    }
    // cout<<par<<" "<<node<<" "<<pathsum<<endl;
    for(auto it: adj[node]){
        int ad = it.first;
        int wt = it.second;

        if(!vis[ad]&&ad!=par){
            if(par!=-1 && mp[par][ad]==0){
                int a = dfs(par, ad, adj, pathsum+wt, cnt, mp);  
            }
            int b = dfs(node, ad, adj, wt, cnt, mp);
            if(wt%2==1 && mp[node][ad]==0){
                cnt++;
                mp[node][ad]=wt;
                mp[ad][node]=wt;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> adj[n];
    int u,v,w;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        adj[u-1].push_back({v-1,w});
        adj[v-1].push_back({u-1,w});
    }
    int cnt = 0;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        dfs(-1,i,adj,0,cnt,dp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}