#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> x(n,0);
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        set<int> s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                s.insert(abs(x[i] - x[j]));
            }
        }
        cout<<s.size()<<"\n";
    }
}