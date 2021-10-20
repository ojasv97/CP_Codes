#include<bitd/stdc++.h>
using namespace std;




long long int solve(vector<int> &a,int i,int &sum, int s){
    if(i==a.size()){
        return 0;
    }
    if(s==1){
        return max(solve(a,i+1,sum+a[i],0),solve(a,i+1,sum,0));
    }
    else{
        return max(solve(a,i+1,sum-a[i],1),solve(a,i+1,sum,1));
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int c;
        cin>>n>>c;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int sum = 0;
        string ans = solve(a,0,sum,1);
        cout<<ans<<endl;
    }
    return 0;
}