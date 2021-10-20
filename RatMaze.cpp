// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
void path(int m[MAX][MAX], int i, int j, int n, vector<string> &s, string st, vector<vector<int>>& vis){
    if(i<0 || j<0 || i>=n ||j>=n|| m[i][j]==0 || vis[i][j]==1){
        return;
    }
    if(i==n-1 && j==n-1 && m[i][j]==1){
        s.push_back(st);
        return;
    }
    vis[i][j]=1;
    st.push_back('U');
    path(m,i-1,j,n,s,st,vis);
    st.pop_back();
    st.push_back('D');
    path(m,i+1,j,n,s,st,vis);
    st.pop_back();
    st.push_back('L');
    path(m,i,j-1,n,s,st,vis);
    st.pop_back();
    st.push_back('R');
    path(m,i,j+1,n,s,st,vis);
    st.pop_back();
    vis[i][j]=0;
}
vector<string> findPath(int m[MAX][MAX], int n) {
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<string> ans;
    path(m,0,0,n,ans,"",vis);
    sort(ans.begin(),ans.end());
    return ans;
}