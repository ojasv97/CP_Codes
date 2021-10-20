#include<bits/stdc++.h>
using namespace std;

int UKS(vector<int>value,vector<int> wt, int cap, int i){
    if(i==0 || cap<=0){
        return 0;
    }
    else{
        if(wt[i-1]<=cap){
            return max(UKS(value,wt,cap-wt[i-1],i)+value[i-1],UKS(value,wt,cap,i-1));
        }
        else{
            return UKS(value,wt,cap,i-1);
        }
    }
}
int main(){
    vector<int> price{1,5,8,9,10,17,17,20};
    vector<int> len{1,2,3,4,5,6,7,8};
    cout<<UKS(price,len,8,price.size());
    return 0;
}