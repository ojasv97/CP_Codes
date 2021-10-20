#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        set<int> s;
        int val;
        for(int i=0;i<n;i++){
            cin>>val;
            if(s.find(val)!=s.end()){
                s.insert(val+1);
            }
            else{
                s.insert(val);
            }
        }
        cout<<s.size()<<"\n";
    }
}