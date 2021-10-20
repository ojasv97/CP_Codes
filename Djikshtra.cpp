#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        return a.first>b.first;
    }
};
int main(){
    int V = 5;
    vector<vector<long int>>mat{{0,4,3,MAX,2},{4,0,5,MAX,MAX},{3,5,0,7,MAX},{MAX,MAX,7,0,1},{2,MAX,MAX,1,0}};
    vector<pair<int,int>>adj[V];
    for(int i=0;i<V;i++){
        for(int j=i;j<V;j++){
            adj[i].push_back({j,mat[i][j]});
            adj[j].push_back({i,mat[i][j]});
        }
    }
    vector<int>prev(V,-1);
    bool visited[V]={false}; //For checking loops
    vector<long int>dist(V,MAX);
    int src = 0;
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;
    q.push({dist[src],src});

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        for(auto i:adj[a]){
            int v = i.first;
            int wt = i.second;
            if(dist[v]>dist[a]+wt){
                dist[v]=dist[a]+wt;
                q.push({dist[v],v});
                prev[v] = a;
            }
        }
    }
    for(auto x:dist){
        cout<<x<<" "; 
    }
    cout<<endl;
    for(auto x:prev){
        cout<<x<<" "; 
    }
    cout<<endl;
    return 0;
}