#include <bits/stdc++.h>
using namespace std;

int fnd(int a, vector<int> &par){
    if(par[a]!=a){
        return fnd(par[a],par);
    }
    else{
        return a;
    }
}
void unin(int a, int b, vector<int>& par){
    int p_a = fnd(a,par);
    int p_b = fnd(b,par);
    if(p_a==p_b){
        return;
    }
    if(p_a<p_b){
        par[b] = p_a;
    }
    else{
        par[a] = p_b;
    }
    return;
}
int main() {
    int t;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        // vector<int> par(n+1,0);
        // for(int i=0;i<n+1;i++){
        //     par[i]=i;
        // }
        int p,q;
        for(int k=0;k<m;k++){
            cin>>p>>q; 
        //     par[p]=p;
        //     par[q]=q;
        //     unin(p,q,par);
        }
        // vector<int> g(n,0);
        // for(int i=1;i<par.size();i++){
        //     g[find(i,par)]++;
        // }
        // int cnt=0;
        // for(auto it:g){
        //     cnt+=it;
        // }
        // cout<<cnt<<endl;
    }
	return 0;
}