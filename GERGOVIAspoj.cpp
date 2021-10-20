#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0){break;}
        vector<int> inhabitants(n,0);
        for(int i=0;i<n;i++){
            cin>>inhabitants[i];
        }
        int buy=0,sell=0;
        long long int cost = 0;
        while(buy<n && sell<n){
            while(inhabitants[buy]<=0){
                buy++;
            }
            while(inhabitants[sell]>=0){
                sell++;
            }
            if(buy<n && sell<n && inhabitants[sell]<0 && inhabitants[buy]>0){
                int a = inhabitants[buy];
                int b = -inhabitants[sell];
                int c = min(a,b);
                inhabitants[sell]+=c;
                inhabitants[buy]-=c;
                cost+=abs(buy-sell)*c;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}