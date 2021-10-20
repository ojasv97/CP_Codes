#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a{3, -4, 2, -3, -1, 7, -5};
    int n = a.size();
    int curr = a[0];
    int mn = a[0];
    for(int i=1;i<n;i++){
        if(curr>0){
            curr=a[i];
        }
        else{
            curr+=a[i];
        }
        mn = min(mn,curr);
    }
    cout<<mn<<endl;
    return 0;
}