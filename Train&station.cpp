#include<bits/stdc++.h>
#include<chrono>
using namespace std;
struct train{
    int name;
    int arrtime;
    int deptime;
    int ori;
    int dest;
    int curr;
    int delay;
    int priority;
};
struct myComp { 
    constexpr bool operator()( 
        train const& a, 
        train const& b) 
        const noexcept 
    { 
        if(abs(a.arrtime-b.arrtime)>0){
            return a.arrtime > b.arrtime;
        }
        else{
            return a.priority > b.priority;
        }
    } 
}; 
struct station{
    vector<train> trains;
    train present;
    int time = 0;
    vector<vector<pair<int,int>>> routes;
};
int main(){
    cout<<"Enter the no. of trains"<<endl;
    int t_count;
    cin>>t_count;
    cout<<"Enter the no.of routes"<<endl;
    int route_count;
    cin>>route_count;
    station myStation;
    for(int i=0;i<route_count;i++){
        vector<pair<int,int>> v;
        myStation.routes.push_back(v);
        int p;
        cout<<"Enter the number of station in each route"<<endl;
        cin>>p;
        cout<<"Enter the station names and time required to reach the curr station for each route"<<endl;
        for(int j=0;j<p;j++){
            int k;
            int t;
            cin>>k;
            cin>>t;
            myStation.routes[i].push_back({k,t});
        }
    }
    for(int i=0;i<route_count;i++){
        for(int j=1;j<(myStation.routes[i]).size();j++){
            myStation.routes[i][j].second=myStation.routes[i][j-1].second + myStation.routes[i][j].second;
        }
    }
    for(int i=0;i<t_count;i++){
        train t;
        cout<<"Enter train name,arr time, dep time,ori,dest,priority"<<endl;
        cin>>priority;
        cin>>t.name;
        cin>>t.arrtime;
        cin>>t.deptime;
        cin>>t.ori;
        cin>>t.dest;
        myStation.trains.push_back(t);
    }
    myStation.present = myStation.trains.top();
    cout<<myStation.present.name;
    // for(int i=0;i<route_count;i++){
    //     for(int j=0;j<(myStation.routes[i]).size();j++){
    //         cout<<myStation.routes[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<60;i++){
        myStation.present=-1;
        if(myStation.present==-1){
            for(auto it:myStation.trains){
                if(it.arrtime==i){
                    myStation.present=it;
                    for(auto pt:myStation.trains){
                        if(pt.arrtime<=it.deptime && pt.arrtime>it.deptime && it!=pt){
                            pt.delay++;
                        }
                    }
                }
            }
            
        }
        else{
            if(myStation.present.deptime==i){
                
            }
        }
    }

    return 0;
}