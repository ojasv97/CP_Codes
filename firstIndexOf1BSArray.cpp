#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int i;
    // while(cin.peek()!='\n'){
    //     cin>>i;
    //     arr.push_back(i);
    // }
    int low=0;
    int high=1;
    if(arr.size()<2){
        if(arr.size()==0){return -1;}
        if(arr.size()==1){
            if(arr[0]==1){return 0;}
            else{return -1;}
        }
    }
    while(true){
        if(arr[high]<1){
            low = high;
            high = high*2;
        }
        else{
            break;
        }
    }
    int mid;
    int res=-1;
    while(low<=high){
        mid = low+(high-low)/2;
        if(arr[mid]<1){
            low = mid+1;
        }
        else{
            res=mid;
            high = mid-1;
        }
    }
    cout<<res<<endl;
    return 0;
}