// Minimum Spanning tree - Hackerearth
#include <bits/stdc++.h>
using namespace std ;

struct data {
    int u = 0 , v = 0 , w = 0 ;
    data(int a,int b, int c){
        u = a; v = b; w = c;
    }
};
bool cmp (const data &a, const data &b ) {
    return a.w < b.w ;
}
int Find ( int a , vector<int>& parent) {
    if ( parent[a] == -1 )
        return a ;
    return parent[a] = Find(parent[a],parent) ;
}
void Union ( int a , int b, vector<int>& parent ) {
    parent[b] = a ;
}
int main () {
    int n,m;
    cin >> n >> m ;
    
    vector<int> parent(n,-1);
    vector<data> edges;

    int a,b,c;
    for ( int i = 0 ; i < m ; i++ ) {
        cin>>a>>b>>c;
        data node(a,b,c);
        edges.push_back(node);
    }
    sort (edges.begin() , edges.end(), cmp);
    int sm = 0 ;
    for (int i = 0 ; i < m ; i++) {
        int a = Find(edges[i].u, parent) ;
        int b = Find(edges[i].v,parent) ;
        if ( a != b ) {
            Union(a,b,parent) ;
            sm += edges[i].w ;
        }
    }
    cout <<sm<< endl ;
    return 0 ;
}