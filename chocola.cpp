#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int r,a,b;
        cin>>a>>b;
        vector<int> x(a,0);
        vector<int> y(b,0);
        for(int i=0;i<a-1;i++){
            cin>>x[i];
        }
        for(int i=0;i<b-1;i++){
            cin>>y[i];
        }
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int hz=1;
        int vr=1;
        int i=0;
        int j=0;
        int cost=0;
        while(i<b && j<a){
            if(x[j]<y[i]){
                cost+=y[i]*vr;
                hz+=1;
                i++;
            }
            else{
                cost+=x[j]*hz;
                vr+=1;
                j++;
            }
        }
        if(i==b){
            while(j<a){
                cost+=x[j]*hz;
                vr+=1;
                j++;
            }
        }
        else if(j==a){
            while(i<b){
                cost+=y[i]*vr;
                hz+=1;
                i++;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}