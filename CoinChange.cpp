#include<bits/stdc++.h>
using namespace std;
int CC(vector<int> coin, int sm, int i){
    if(i==0 || sm==0){
        return 0;
    }
    else{
        if(sm >= coin[i-1]){
            if(sm==coin[i-1]){
                return 1+CC(coin,sm,i-1);
            }
            else{
                return CC(coin,sm-coin[i-1],i)+CC(coin,sm,i-1);
            }
        }
        else{
            return CC(coin,sm,i-1);
        }
    }
}
int main(){
    vector<int> coin{1,2,3};
    cout<<CC(coin,5,3);
    return 0;
}