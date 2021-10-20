#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> &arr, int val){
    int low = 0;
    int high = arr.size()-1;
    while(high-low>1){
        int mid = (low+high)/2;
        if(arr[mid]<val){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    if(arr[low]==val){
        return low;
    }
    else if(arr[high]==val){
        return high;
    }
    else{
        return -1;
    }
}

int BS_lowerB(vector<int> &arr, int val){
    int low = 0;
    int high = arr.size()-1;
    while(high-low>1){
        int mid = (low+high)/2;
        if(arr[mid]<val){
            low = mid+1;
        }
        else{
            high = mid; 
        }
    }
    if(arr[low]>=val){
        return low;
    }
    else if(arr[high]>=val){
        return high;
    }
    else{
        return -1;
    }
}

int BS_upperB(vector<int> &arr, int val){
    int low = 0;
    int high = arr.size()-1;
    while(high-low>1){
        int mid = (low+high)/2;
        if(arr[mid]<=val){
            low = mid+1;
        }
        else{
            high = mid; 
        }
    }
    if(arr[low]>val){
        return low;
    }
    else if(arr[high]>val){
        return high;
    }
    else{
        return -1;
    }
}


int BS_revlowerB(vector<int> &arr, int val){
    int low = 0;
    int high = arr.size()-1;
    while(high-low>1){
        int mid = (low+high)/2;
        if(arr[mid]<=val){
            low = mid;
        }
        else{
            high = mid-1; 
        }
    }
    if(arr[high]<=val){
        return high;
    }
    else if(arr[low]<=val){
        return low;
    }
    else{
        return -1;
    }
}

int BS_revupperB(vector<int> &arr, int val){
    int low = 0;
    int high = arr.size()-1;
    while(high-low>1){
        int mid = (low+high)/2;
        if(arr[mid]<val){
            low = mid;
        }
        else{
            high = mid-1; 
        }
    }
    if(arr[high]<val){
        return high;
    }
    else if(arr[low]<val){
        return low;
    }
    else{
        return -1;
    }
}

int main(){
    vector<int> x{1,2,3,4,7};
    // cout<<BS(x,5);
    // cout<<BS_lowerB(x,8);
    // cout<<BS_upperB(x,7);
    // cout<<BS_revlowerB(x,9);
    cout<<BS_revupperB(x,7);
}