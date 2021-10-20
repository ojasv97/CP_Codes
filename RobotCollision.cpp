#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n,0);
        vector<int> dir(n,0);
        bool flag = true;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        char c;
        for(int i=0;i<n;i++){
            cin>>c;
            if(c=='L'){
                dir[i]=-1;
            }
            else{
                dir[i]=1;
            }
        }
        vector<int> dp(m,-1);
        bool flag_left=false;
        bool flag_right=false;
        while(true){
            for(int i=0;i<n;i++){
                if(dir[i]==-1){
                    flag_left=true;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(dir[i]==1){
                    flag_right=true;
                    break;
                }
            }
            if(flag_left && flag_right){
                for(int i=0;i<m;i++){
                    a[i]++;
                }
            }
            else{
                break;
            }
        }
    }
    return 0;
}