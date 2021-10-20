#include<bits/stdc++.h>
using namespace std;
int seg[4 0]={0};
void build(vector<int>& a,int i, int l, int h){
    if(l==h){
        seg[i] = a[l];
    }
    else{
        int m = (l+h)/2;
        build(a,2*i+1,l,m);
        build(a,2*i+2,m+1,h);
        seg[i] = seg[2*i+1]+seg[2*i+2];
    }
}

int suum(int i,int low, int high, int l, int r){
    if(l>r){
        return 0;
    }
    if(low==l && high==r){
        return seg[i];
    }
    int mid = (low+high)/2;
    return suum(2*i, low, mid, l, min(r,mid)) + suum(2*i+1, mid+1, high, max(l,mid+1), r);
}

void update(int i, int low, int high, int pos, int new_val){
    if(low==high){
        seg[i] =  new_val;
    }
    else{
        int mid  = (low+high)/2;
        if(pos<=mid){
            update(2*i, low, mid, pos, new_val);
        }
        else{
            update(2*i+1, mid+1,high, pos, new_val);
        }
        seg[i] = seg[2*i]+seg[2*i+1];
    }
}
int main(){
    vector<int> a{1,2,3,4,5,6};
    build(a,1,0,a.size()-1);
    for(auto x:seg){
        cout<<x<<" ";
    }
    cout<<endl;
    update(1,0,a.size()-1,2,9);
    for(auto x:seg){
        cout<<x<<" ";
    }
    return 0;
}
