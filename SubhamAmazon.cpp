#include<bits/stdc++.h>
using namespace std;

int distance(int x, int y){
    int d = x*x + y*y;
    return d;
}
auto compare = [&](pair<int,int> &a, pair<int,int> &b){
    if(distance(a.first,a.second)==distance(b.first,b.second)){
        return abs(a.first)>abs(b.first);
    }
    else{
        return distance(a.first,a.second)>distance(b.first,b.second);
    }
};
bool comp(pair<int,int> &a, pair<int,int> &b){
    if(distance(a.first,a.second)==distance(b.first,b.second)){
        return abs(a.first)<abs(b.first);
    }
    else{
        return distance(a.first,a.second)<distance(b.first,b.second);
    }
}
int main(){
    vector<vector<int>> allocations{{3,6},{2,4},{5,3},{2,7},{1,8},{7,9}};
    int numDeliveries = 3;
    vector<pair<int,int>> con;
    for(auto it:allocations){
        con.push_back({it[0],it[1]});
    }

    //M1 (Min Heap)
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> p(compare);
    for(auto it:con){
        p.push(it);
    }
    int k = numDeliveries;
    while(k--){
        pair<int,int> q = p.top();
        p.pop();
        cout<<q.first<<" "<<q.second<<endl;
    }

    //M2 (sort)
    sort(con.begin(),con.end(),comp);
    cout<<endl;
    for(int i=0;i<con.size();i++){
        cout<<con[i].first<<" "<<con[i].second<<endl;
    }
    return 0;
}