// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int visited[101]={0};
bool check(bool graph[101][101], int V, int c, int node, vector<int>&col){
    for(int i=0;i<V;i++){
        if(graph[node][i]==true && col[i]==c){
            return false;
        }
    }
    return true;
}
void solve(bool graph[101][101], int m, int V, vector<int> &col, int node, unordered_map<int,int> &mp, bool &ans){
    if(node==V){
        ans = true;
        return;
    }
    for(int c=1;c<=m;c++){
        if(check(graph,V,c,node,col)){
            col[node] = c;
            mp[c] = node;
            solve(graph,m,V,col,node+1,mp,ans);
            mp[c]=-1;
            col[node] = 0;
        }
    }
}

bool graphColoring(bool graph[101][101], int m, int V) {
    bool ans = false;
    unordered_map<int,int> mp;
    for(int i=1;i<=m;i++){
        mp[i]=-1;
    }
    vector<int> col(V,0);
    solve(graph,m,V,col,0,mp,ans);
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends