#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int T=1;
    while(T<=t){
        int n;
        cin>>n;
        vector<int> I;
        vector<int> O;
        string v1;
        cin>>v1;
        for(int i=0;i<v1.length();i++){
            if(v1[i]=='Y'){
                I.push_back(1);
            }
            else{
                I.push_back(0);
            }
        }
        string v2;
        cin>>v2;
        for(int i=0;i<v2.length();i++){
            if(v2[i]=='Y'){
                O.push_back(1);
            }
            else{
                O.push_back(0);
            }
        }
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<vector<char>> ans(n,vector<char>(n,'N'));
        for(int i=0;i<n;i++){
            adj[i][i]=1;
            if(i==0){
                if(O[i]&&I[i+1]==1){adj[i][i+1]=1;}
                if(I[i]&&O[i+1]==1){adj[i+1][i]=1;}
            }
            if(i==n-1){
                if(O[i]&&I[i-1]==1){adj[i][i-1]=1;}
                if(I[i]&&O[i-1]==1){adj[i-1][i]=1;}
            }
            else{
                if(O[i]&&I[i+1]==1){adj[i][i+1]=1;}
                if(O[i]&&I[i-1]==1){adj[i][i-1]=1;}
                // if(I[i]&&O[i-1]==1){adj[i-1][i]=1;}
                // if(I[i]&&O[i+1]==1){adj[i+1][i]=1;}
            }
        }
        for(int i=0;i<n;i++){
            queue<int> q;
            bool visited[n]={false}; 
            ans[i][i]='Y';
            visited[i] = true;
            q.push(i); 
            while (!q.empty()) {
                int s = q.front(); 
                q.pop();
                for (int u=0;u<n;u++){
                    if(adj[s][u]==1){
                        if (visited[u]) continue;
                        visited[u] = true; 
                        ans[i][u]='Y';
                        q.push(u);
                    }
                }
            }
        }
        cout<<"Case #"<<T<<":"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
        T++;
    }
    return 0;
}