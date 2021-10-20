#include<bits/stdc++.h>
using namespace std;

int predicate(vector<vector<int>> &A, int mid){
    int count = 0;
    for(int i=0;i<A.size();i++){
        count+= upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin();
    }
    cout<<mid<<" "<<count<<endl;
    return count<=(A.size()*A[0].size())/2;
}

int BS(vector<vector<int>> &A, int val){
    int low = INT_MIN,high = INT_MAX;
    int mid;
    while(high>low+1){
        mid = (high+low)>>1;
        if(predicate(A,mid)){
            low = mid;
        }
        else{
            high = mid-1;
        }

    }
    if(predicate(A,low)==false)return low;
    return high;
}

findMedian(vector<vector<int> > &A) {
    int low = INT_MIN;
    int high = INT_MAX; 
    int n = A.size();
    int m = A[0].size(); 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            cnt += upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        cout<<mid<<" "<<cnt<<endl;
        if(cnt <= (n * m) / 2) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}

int main(){
    vector<vector<int>> A{{1, 2, 5},{4,5,6},{1,5,7}};
    int n = A.size();
    int m = A[0].size();
    int x = BS(A,(n*m)/2);
    cout<<endl;
    int y = findMedian(A);
    cout<<x<<" "<<y<<endl;
    return 0;
}