#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> l){
    int cost=0;
    for(int i=0;i<l.size()-1;i++){
        int j = min_element(l.begin()+i, l.end()) - l.begin();
        int p = i;
        int q = j;
        while(p<q){
            swap(l[p],l[q]);
            p++;
            q--;
        }
        cost+=j-i+1;
    }
    return cost;
}
bool permute(vector<int> a, int l, int r, int &cost, vector<int> &ans)
{
    if (l == r){
        if(fun(a) == cost){
            ans = a;
            return true;
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            bool y = permute(a, l+1, r, cost, ans);
            if(y){
                return true;
            }
            swap(a[l], a[i]);
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    int k=t;
    while(t--){
        int n;
        cin>>n;
        int cost;
        cin>>cost;
        vector<int> l(n,0);
        for(int i=0;i<n;i++){
            l[i]=i+1;
        }
        vector<int> ans(n,0);
        bool y = permute(l,0,l.size()-1,cost, ans);
        if(y){
            cout<<"Case #"<<k-t<<": ";
            for(auto it:ans){cout<<it<<" ";}
            cout<<endl;
        }
        else{
            cout<<"Case #"<<k-t<<": "<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}