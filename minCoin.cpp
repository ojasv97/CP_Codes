#include<bits/stdc++.h>
using namespace std;
int MC(vector<int> coin, int sm, int i){
    if(sm==0){
        return INT_MAX-1;
    }
    else if(i==0 && sm!=0){
        return 0;
    }
    else{
        if(sm >= coin[i-1]){
            if(sm==coin[i-1]){
                return 1;
            }
            else{
                return 1+min(MC(coin,sm-coin[i-1],i),MC(coin,sm,i-1));
            }
        }
        else{
            return MC(coin,sm,i-1);
        }
    }
}
int main(){
    vector<int> coin{1,2,3};
    cout<<MC(coin,5,3);
    return 0;
}