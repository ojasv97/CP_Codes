/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int src, int tar, vector<int>adj[], vector<int>&vis, vector<int> cur, vector<pair<int,int>> &trav){
    vis[node]=1;
    cur.push_back(node);
    bool flag=false;
    for(auto it: adj[node]){
        if(!vis[it]){
            flag = true;
            dfs(it,src,tar,adj,vis,cur,trav);
        }
    }
    if(!flag){
        int s=-1;
        int t=-1;
        for(int i=0;i<cur.size();i++){
            if(src==cur[i]){
                s=i;
            }
            if(tar==cur[i]){
                t=i;
            }
        }
        if(s!=-1 && t!=-1){
            trav.push_back({s,t});
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>adj[n];
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> curr;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        vector<int> vis(n,0);
        vector<pair<int,int>> trav;
        dfs(0,c-1,b-1,adj,vis,curr,trav);
        if(trav.size()==0){
            cout<<"NO"<<endl;
        }
        else{
            int m = trav[0].first;
            int n = trav[0].second;
            if(a==0 && m>n){
                cout<<"YES"<<endl;
            }
            else if(a==1 && n>m){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}