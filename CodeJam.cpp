#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int w = 1;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]==v[i]){
                continue;
            }
            pq.push(v[i+1]-v[i]-1);
        }
        int end_g=0;
        if(v[v.size()-1]!=k){
            end_g = k-v[v.size()-1];
        }
        int g1 = pq.top();
        pq.pop();
        int g2 = pq.top();
        float nm = 0;
        if(g1%2==0){
            g1=g1/2;
        }
        else{
            g1=g1/2+1;
        }
        if(g2%2==0){
            g2=g2/2;
        }
        else{
            g2=g2/2+1;
        }
        int mn = min(min(g1,g2),end_g);
        int a = max(max(g1,g2),end_g);
        int b = g1+g2+end_g - (mn+a);
        float d = (float)k;
        float ans = (float) (a+b)/d;
        cout<<"Case #"<<w++<<":"<<(float)ans<<endl;
    }
    return 0;
}