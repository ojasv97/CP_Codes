#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>&,int);
void rec(vector<int> &arr,int i, int j){
    if(arr.size()==1){
        return;
    }
    int temp = arr[j-1];
    arr.pop_back();
    rec(arr,i,j-1);
    insert(arr,temp);
    // for(int t=i;t<j-1;t++){
    //     if(arr[t]>arr[t+1]){swap(arr[t],arr[t+1]);}
    //     else{break;}
    // }
}
void insert(vector<int>&arr,int val){
    if(arr.size()==0 || arr[arr.size()-1]<=val){
        arr.push_back(val);
        return;
    }
    int temp = arr[arr.size()-1];
    arr.pop_back();
    insert(arr,val);
    arr.push_back(temp);
}
int main(){
    vector<int> a{4,6,3,1,8,9,2};
    rec(a,0,a.size());
    for(auto x:a){cout<<x<<" ";}
    return 0;
}