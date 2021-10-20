/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

int timer=1;
void dfs(vector<int>& vis, vector<int>&tin, vector<int> &low, int node, int parent, vector<int> adj[], set<pair<int,int>>&bridge){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it:adj[node]){
        if(parent==it){
            continue;
        }
        if(vis[it]){
            low[node] = min(low[node],tin[it]);
        }
        else{
            dfs(vis,tin,low,it,node,adj,bridge);
            low[node] = min(low[node],low[it]);
            if(tin[node]<low[it]){
                bridge.insert({node,it});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    int a,b;
    vector<int> A;
    vector<int> B;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        A.push_back(a);
        B.push_back(b);
    }
    vector<int> vis(n,0);
    vector<int> tin(n,0);
    vector<int> low(n,0);
    set<pair<int,int>> bridge;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(vis,tin,low,i,-1,adj,bridge);
        }
    }
    int q;
    cin>>q;
    int p;
    for(int i=0;i<q;i++){
        cin>>p;
        a = A[p-1];
        b = B[p-1];
        if(bridge.find({a-1,b-1})==bridge.end() && bridge.find({b-1,a-1})==bridge.end()){
            cout<<"Happy"<<endl;
        }
        else{
            cout<<"Unhappy"<<endl;
        }
    }
    return 0;
}