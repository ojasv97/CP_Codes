#include<bits/stdc++.h>
#include<string>
using namespace std;
void solve(vector<int> &v, int ci, int ti,vector<vector<int>>& ans){
    if(ci>ti){
        ans.push_back(v);
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            v[i]=ci;
            solve(v,ci+1,ti,ans);
            v[i]=0;
        }
    }
}
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> v(n,0);
    int ci=1;
    vector<vector<int>> a;
    solve(v,ci,n,a);
    sort(a.begin(),a.end());
    for(auto x:a[k-1]){
        cout<<x;
    }
    cout<<endl;
    return 0;
}