#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &g, int i, int j){
    if(i>=0 && i<=g.size()-1 && j>=0 && j<=g[0].size()-1){
        return true;
    }
    return false;
}
bool isValid(vector<vector<int>> &g, int i, int j){
    if(check(g,i-1,j) && check(g,i+1,j) && check(g,i,j-1) && check(g,i,j+1)){
        return ((!check(g,i-1,j) | g[i-1][j]) && g[i+1][j] && g[i][j-1] && g[i][j+1];
    }

}
void solve(vector<vector<int>> &g, vector<pair<int,int>> move, int i, int j, int& mn, int cnt, int ans){
    int ni,nj;
    if(i==g.size()){
        return;
    }
    if(j==g[0].size()){
        if(cnt<mn){
            mn = cnt;
        }
    }
    else{
        for(auto it:move){
            ni = it.first + i;
            nj = it.second + j;
            cout<<ni<<" "<<nj<<endl;
            if(check(g,ni,nj)){
                cnt++;
                solve(g,move,ni,nj,mn,cnt);
                cnt--;
            }
        }

    }
}
int main(){
    vector<pair<int,int>> moves{{1,0},{-1,0},{0,-1},{0,1}};
    int r,c;
    cin>>r>>c;
    vector<vector<int>> g(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>g[i][j];
        }
    }
    int mn;
    int cnt;
    // for(int i=0;i<r;i++){
        mn = INT_MAX;
        cnt=0;
        solve(g,moves,0,0,mn,cnt);
    // }
    cout<<mn;
    return 0;
}

