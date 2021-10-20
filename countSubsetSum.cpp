#include<bits/stdc++.h>
using namespace std;
int CSS(vector<int>a,int s,int i,int count){
    if(i<0){
        if(s==0){count++;return count;}
        else{return count;}
    }
    else{
        if(s==0){count++;return count;}
        else{
            if(a[i]<=s){
                return CSS(a,s-a[i],i-1,count)+CSS(a,s,i-1,count);
            }
            else{
                return CSS(a,s,i-1,count);
            }
        }
    }
}
int main(){
    vector<int> b{3,4,2,1,7};
    int s = 20;
    cout<<CSS(b,s,b.size()-1,0)<<endl;
    return 0;
}