#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,w;
        cin>>n>>k>>w;
        vector<int> L(n,0);
        vector<int> H(n,0);
        long long int la,lb,lc,ld,ha,hb,hc,hd;
        unordered_map<int,pair<int,int>> start;
        unordered_map<int,pair<int,int>> end;
        unordered_map<int,pair<int,int>> polygon;
        for(int i=0;i<k;i++){
            cin>>L[i];
            start[L[i]]={-1,-1};
            end[L[i]+w]={-1,-1};
        }
        cin>>la>>lb>>lc>>ld;
        for(int i=0;i<k;i++){
            cin>>H[i];
            start[L[i]]={0,H[i]};
            end[L[i]+w]={0,H[i]};
        }
        cin>>ha>>hb>>hc>>hd;
        for(int i=k;k<n;k++){
            L[i]=((la*L[i-2]+lb*L[i-1]+lc)%ld)+1;
            H[i]=((ha*H[i-2]+hb*H[i-1]+hc)%hd)+1;
        }
        vector<int> P;
        int p = 2*(H[0]+w);
        P.push_back(p);
        polygon[L[0]]={0,H[0]};
        polygon[L[0]+w]={0,H[0]};
        for(int i=1;i<n;i++){
            int flag=0;
            for(int j=L[i]+w;j>=L[i];j--){
                if(flag==0){
                    p++;
                }
                if(polygon.find(j)!=polygon.end()){
                    flag=1;
                    if(j==L[i]){
                        int curr_h = polygon[j].second-polygon[j].first;
                        int A = polygon[j].first;
                        int B = polygon[j].second;
                        int C = H[i];
                        int lar = A > B ? (A > C ? A : C) : (B > C ? B : C);
                        int sec_lar = A > B ? (B > C ? B : C) : (A > C ? A : C);
                        if(lar==H[i]){
                            polygon[j]={sec_lar,lar};
                        }
                        int new_h = polygon[j].second-polygon[j].first;
                        if(new_h>curr_h){
                            p = p-curr_h+new_h;
                        }
                    }
                    else{
                        int A = polygon[j].first;
                        int B = polygon[j].second;
                        int C = H[i];
                        int curr_h = polygon[j].second-polygon[j].first;
                        int lar = A > B ? (A > C ? A : C) : (B > C ? B : C);
                        int sec_lar = A > B ? (B > C ? B : C) : (A > C ? A : C);
                        if(lar==H[i]){
                            polygon.erase(j);
                            continue;
                        }
                        else{
                            polygon[j]={sec_lar,lar};
                        }          
                        int new_h = polygon[j].second-polygon[j].first;
                        if(new_h>curr_h){
                            p = p-curr_h+new_h;
                        }              
                    }
                }
            }
            // if(polygon.find(L[i])!=polygon.end()){polygon[L[i]]={0,H[i]};}
            // if(polygon.find(L[i]+w)!=polygon.end()){polygon[L[i]+w]={0,H[i]};}
            // if(L[i]==L[i-1]+w){
            //     p=p-H[i-1]+abs(H[i]-H[i-1])+2*w+H[i];
            // }
            // else if(L[i]<L[i-1]+w){
            //     p=p-H[i-1]+abs(H[i]-H[i-1])+2*(L[i]-L[i-1])+H[i];
            // }
            // else{
            //     p += 2*(H[i]+w);
            // }
            P.push_back(p);
        }
        int ans=1;
        for(int i=0;i<P.size();i++){
            ans=(ans*P[i])%1000000007;
        }
        for(auto x:P){cout<<x<<" ";}
        cout<<endl;
    }
    return 0;
}