#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> &v, int i, int j){
    int cnt=0;
    if(i-1>=0 && j-1>=0){
        if(v[i-1][j-1]==1){
            cnt++;
        }
    }
    if(i-1>=0 && j>=0){
        if(v[i-1][j]==1){
            cnt++;
        }
    }
    if(i-1>=0 && j+1<v[0].size()){
        if(v[i-1][j+1]==1){
            cnt++;
        }
    }
    if(i>=0 && j+1<v[0].size()){
        if(v[i][j+1]==1){
            cnt++;
        }
    }
    if(i+1<v.size() && j+1<v[0].size()){
        if(v[i+1][j+1]==1){
            cnt++;
        }
    }
    if(i+1<v.size()){
        if(v[i+1][j]==1){
            cnt++;
        }
    }
    if(i+1<v.size() && j-1>=0){
        if(v[i+1][j-1]==1){
            cnt++;
        }
    }
    if(j-1>=0){
        if(v[i][j-1]==1){
            cnt++;
        }
    }
    return cnt;
}

void print(vector<vector<int>> &life){
    for(int i=0;i<life.size();i++){
        for(int j=0;j<life[0].size();j++){
            cout<<life[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

vector<vector<int>> gol(vector<vector<int>> &life){
    vector<vector<int>> temp(life.size(),vector<int>(life[0].size(),0));
    int count;
    for(int i=0;i<life.size();i++){
        for(int j=0;j<life[0].size();j++){
            count = check(life,i,j);
            if(life[i][j]==1 && (count<2 || count>3)){
                temp[i][j]=0;
            }
            else if(life[i][j]==1 && (count==2 || count==3)){
                temp[i][j]=1;
            }
            else if(life[i][j]==0 && count==3){
                temp[i][j]=1;
            }
        }
    }
    return temp;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> l(n,vector<int>(m,0));
    l[1][5]=1;
    l[2][3]=1;
    l[2][4]=1;
    l[2][5]=1;
    l[3][4]=1;
    int k=10;
    while(k--){
        l = gol(l);
        print(l);
    }
    return 0;
}