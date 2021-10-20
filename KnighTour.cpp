#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &board, int x, int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8
            && board[x][y] == 0);
}
void solve(vector<vector<int>> &board, int i, int j, vector<pair<int,int>> &moves, int count,int& ans){
    if(count==65){
        ans=1;
        return;
    }
    int ni,nj;
    for(auto it: moves){
        ni = it.first+i;
        nj = it.second+j;
        if(check(board,ni,nj)){
            board[ni][nj]=count;
            solve(board,ni,nj,moves,count+1,ans);
            if(ans==1){
                return;
            }
            board[ni][nj] = 0;
        }
    }
    return;
}

int main(){
    vector<vector<int>> graph(8,vector<int>(8,0));
    vector<pair<int,int>>moves{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    int c = 2;
    graph[0][0]=1;
    int ans;
    solve(graph,0,0,moves,c,ans);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
