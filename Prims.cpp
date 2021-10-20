#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        return a.first>b.first;
    }
};
int main(){
    int V,m;
    cin>>V>>m;
    int a,b,w;
    vector<pair<int,int>>adj[V];
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});
        adj[b-1].push_back({a-1,w});
    }
    vector<int>mst(V,0);
    vector<int> parent(V,-1);
    vector<long int>dist(V,MAX);

    int src = 0;
    dist[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;
    q.push({dist[src],src});

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        mst[a]=1;
        for(auto i:adj[a]){
            int v = i.first;
            int wt = i.second;
            if(mst[v]==0 && dist[v]>+wt){
                dist[v]=wt;
                q.push({dist[v],v});
                parent[v]=a;
            }
        }
    }
    int sm=0;
    for(auto x:dist){
        cout<<x<<" ";
        sm+=x;
    }
    cout<<sm<<endl;
    return 0;
}