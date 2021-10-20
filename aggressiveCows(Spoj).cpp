#include<bits/stdc++.h>
using namespace std;

int N = 1e9;
bool predicate(vector<int>& position, int v, int m){
    int cnt = position.size();
    int prev = -1;
    for(int i=0;i<position.size();i++){
        if(position[i]-prev>=v || prev==-1){
            prev = position[i];
            m--;
        }
        if(m==0){
            break;
        }
    }
    return m==0;
}
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int low = 0, high = N, mid;
    while(high-low>1){
        mid = (low+high)/2;
        if(predicate(position, mid, m)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    if(predicate(position,high,m)){
        return high;
    }
    else if(predicate(position,low,m)){
        return low;
    }
    else{
        return -1;
    }
}
int main(){
	vector<int> a{1,2,4,3,7};
	cout<<maxDistance(a,3);
}