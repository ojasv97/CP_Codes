#include<bits/stdc++.h>
using namespace std;

int sum(int i, vector<int> &bit){
    int ans = 0;
    for(;i>0;i-=(i&-i)){
        ans+=bit[i];
    }
    return ans;
}

void update(int i, int x, vector<int> &bit){
    for(;i<bit.size();i+=(i&-i)){
        bit[i]+=x;
    }
}

void build(vector<int> &bit, vector<int>& arr){
    for(int i=1;i<=arr.size();i++){
        update(i, arr[i-1], bit);
    }
}
int range_sum(int l, int r, vector<int> &bit){
    return sum(r,bit)-sum(l-1,bit);

}
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int>bit(arr.size()+1,0);
    build(bit,arr);
    cout<<sum(4,bit)<<endl;
    cout<<range_sum(2,5,bit)<<endl;
    return 0;
}