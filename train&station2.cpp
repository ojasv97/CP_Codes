#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


struct train
{
	int trainNo;
	int arrtime;
	int deptime;
	int delay;
	int route;
	int destination;
};
bool comparison(train a,train b)
{
	if(abs(a.arrtime-b.deptime)>0){
		return(a.arrtime<b.arrtime);
	}
	else{
		return a.trainNo<b.trainNo;
	}
}
struct station{
    vector<train> arriving_trains;
    train* present;
	int routes;
};
int main(){
    cout<<"Enter the no. of trains"<<endl;
    int N;
    cin>>N;
	cout<<"Enter the no. of destinations"<<endl;
	int M;
	cin>>M;
    cout<<"Enter the no.of routes"<<endl;
    int K;
    cin>>K;
    station myStation;
	myStation.routes=K;
    for(int i=0;i<N;i++){
        train t;
        t.delay=0;
        cout<<"Enter train no, route, arr time, dep time, destination for "<<i<<"st train."<<endl;
		cin>>t.trainNo;
		cin>>t.route;
        cin>>t.arrtime;
        cin>>t.deptime;
		cin>>t.destination;
        myStation.arriving_trains.push_back(t);
    }
	myStation.present=nullptr;
	int begin_time=0;
	cout<<"Enter the starting time for the 60 minutes span"<<endl;
	cin>>begin_time;
	int end_time=begin_time+60;
	int i=begin_time;
    while(i<end_time){
        if(myStation.present==nullptr){
			sort(myStation.arriving_trains.begin(),myStation.arriving_trains.end(),comparison);
            auto it = myStation.arriving_trains[0];
            if(it.arrtime+it.delay==i){
				myStation.present=&it;
				while(i<it.deptime+it.delay){
					if(i%5==0){
						cout<<"TIME:"<<i<<"minutes"<<endl;
						cout<<"Train currently in the station is TRAIN NO:"<<myStation.present->trainNo<<endl;
						cout<<"Train No || Scheduled AT || Scheduled DT || Actual AT || Actual DT || Delay"<<endl;
						for(auto jt:myStation.arriving_trains){
						    cout<<jt.trainNo<<"            "<<jt.arrtime<<"               "<<jt.deptime<<"              "<<jt.arrtime+jt.delay<<"            "<<
						    jt.deptime+jt.delay<<"            "<<jt.delay<<endl;
						}
						cout<<"-----------------------------------------------------------------------------"<<endl;
					}
					 for(int j=1;j<myStation.arriving_trains.size();j++){
						if(myStation.arriving_trains[j].arrtime+myStation.arriving_trains[j].delay==i && it.trainNo!=myStation.arriving_trains[j].trainNo){
							myStation.arriving_trains[j].delay++;
						}
					}
					i++;
					if(i>=60){
						break;
					}
				}
				myStation.present=nullptr;
				myStation.arriving_trains.erase(myStation.arriving_trains.begin());
				continue;
            }
			else{
				if(i%5==0){
					cout<<"TIME:"<<i<<"minutes"<<endl;
					cout<<"No train is currently in the station"<<endl;
					cout<<"Train No || Scheduled AT || Scheduled DT || Actual AT || Actual DT || Delay"<<endl;
					for(auto jt:myStation.arriving_trains){
						cout<<jt.trainNo<<"              "<<jt.arrtime<<"             "
						<<jt.deptime<<"                 "<<jt.arrtime+jt.delay<<"              "<<jt.deptime+jt.delay<<"       "<<jt.delay<<endl;
					}
					cout<<"---------------------------------------------------------------------------------"<<endl;
				}
				i++;
			}
            
        }
    }
    return 0;
}
