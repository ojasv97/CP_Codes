#include<bits/stdc++.h>
using namespace std;
bool SS(vector<int>a,int s,int i){
    if(i<0){
        if(s==0){return true;}
        else{return false;}
    }
    else{
        if(s==0){return true;}
        else{
            if(a[i]<=s){
                return SS(a,s-a[i],i-1)|SS(a,s,i-1);
            }
            else{
                return SS(a,s,i-1);
            }
        }
    }
}
int main(){
    vector<int> b{3,4,2,1,7};
    int s = 11;
    cout<<SS(b,s,b.size()-1);
    return 0;
}