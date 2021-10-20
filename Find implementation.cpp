#include<bits/stdc++.h>
using namespace std;
class Disjoint_Set { 
    int n;
    vector<int> parent;
    vector<int> rank;
public: 
    Disjoint_Set(int n){
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        makeSet();
    } 
    void makeSet() 
    { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
        } 
    }  
    int Find(int x) 
    { 
        if (parent[x]!= x) {  
            parent[x] = Find(parent[x]); 
        } 
        return parent[x]; 
    }
    void Union(int x, int y) 
    { 
        int xset = Find(x);
        int yset = Find(y); 
        if(xset == yset){
            return;
        }
        if (rank[xset] < rank[yset]){ 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]){ 
            parent[yset] = xset; 
        } 
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
};
int main(){
    int n=7;
    // cin>>n;
    Disjoint_Set d(n);
    d.Union(0,2);
    d.Union(1,3);
    d.Union(1,5);
    bool check[n]{false};
    for(int i=0;i<n;i++){
        check[d.Find(i)]=true;
    }

    // Print the disjoint sets
    cout<<"The disjoint sets are:\n";
    for(int i=0;i<n;i++){
        if(check[i]==true){
            cout<<i;
            for(int j=0;j<n;j++){
                if(d.Find(j)==i && j!=i){
                    cout<<"--"<<j;
                }
            }
            cout<<endl;
        }
    }
    cout<<"Find of all the values in the set are:\n";
    for(int i=0;i<n;i++){
        cout<<"Find("<<i<<") is "<<d.Find(i)<<endl;
    }
    return 0;
}