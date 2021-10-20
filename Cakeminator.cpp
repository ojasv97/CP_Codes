#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,r;
    char temp;
    cin>>r>>c;
    vector<vector<int>> cake(r,vector<int>(c,0));
    vector<int> row(r,0);
    vector<int> col(c,0);
    int devil=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>temp;
            if(temp=='S'){cake[i][j]=-1;row[i]=1;col[j]=1;devil++;}
            else{cake[i][j]=0;}
        }
    }
    int count=0;
    int no_rows=0;
    if(r>c){
        for(int i=0;i<r;i++){
            if(row[i]==0){count+=c;row[i]=1;no_rows++;}
        }
        for(int i=0;i<c;i++){
            if(col[i]==0){count+=r-no_rows;col[i]=1;}
        }
    }
    else{
        for(int i=0;i<c;i++){
            if(col[i]==0){count+=r;col[i]=1;no_rows++;}
        }
        for(int i=0;i<r;i++){
            if(row[i]==0){count+=c-no_rows;row[i]=1;}
        }
    }
    cout<<count<<endl; 
    return 0;
}