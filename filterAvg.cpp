#include<bits/stdc++.h>
using namespace std;

int fill_filter(vector<vector<int>> &v, vector<vector<int>> &f, int i, int j){  //O(r^2)
    int count=0;
    if( i+f.size()>v.size() || j+f[0].size()>v[0].size() ){
        return v[i][j];
    }

    for(int p=i;p<i+f.size();p++){
        for(int q=j;q<j+f[0].size();q++){
            count+=v[p][q];
        }
    }

    count = count/(f.size()*f[0].size());
    return count;
    
}
vector<vector<int>> filter(vector<vector<int>> &v, int filter){
    vector<vector<int>> f(filter,vector<int>(filter,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j] = fill_filter(v,f,i,j);
        }
    }
    return v;
}

int main(){
    vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
    int fil = 2;
    v = filter(v,fil);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
