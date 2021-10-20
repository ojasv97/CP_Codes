#include<bits/stdc++.h>
using namespace std;
void dfs(int v, vector<vector<int>> mat, vector<int> &vis){
    vis[v]=1;
	for(int i=0;i<mat[v].size();i++){
        int child = mat[v][i];
		if(vis[child]==0){
			dfs(child,mat,vis);
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	int a,b;
	vector<vector<int>> mat;
	vector<int> c;
	for(int i=0;i<n+1;i++){
		mat.push_back(c);
	}
	vector<int> vis(n+1,0);
	for(int i=0;i<e;i++){
		cin>>a>>b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
    // for(auto it:mat){
    //     for(auto ot:it){
    //         cout<<ot<<" ";
    //     }
    //     cout<<endl;
    // }
	int count=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,mat,vis);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}