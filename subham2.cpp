#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int mx = 0;
    int cnt = 0;
    for(int i=0;i<32;i++){
        for(int j=0;j<A.size();j++){
            if(A[j]!=0){
                cnt+=(A[j]&1);
                A[j] = A[j]>>1;
            }
        }
        mx = max(cnt,mx);
        cnt=0;
    }
    cout<<mx;
    return 0;
}