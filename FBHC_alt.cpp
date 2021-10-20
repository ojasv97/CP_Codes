#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k,w;
        cin>>n>>k>>w;
        vector<long long int> L(n,0);
        vector<long long int> H(n,0);
        long long int la,lb,lc,ld,ha,hb,hc,hd;
        for(int i=0;i<k;i++){
            cin>>L[i];
        }
        cin>>la>>lb>>lc>>ld;
        for(int i=0;i<k;i++){
            cin>>H[i];
        }
        cin>>ha>>hb>>hc>>hd;
        for(int i=k;i<n;i++){
            L[i]=((la*L[i-2]+lb*L[i-1]+lc)%ld)+1;
            H[i]=((ha*H[i-2]+hb*H[i-1]+hc)%hd)+1;
        }
        long long int curr_maxl = 0;
        long long int curr_maxh = 0;
        vector<int> P;
        long long int p = 2*(H[0]+w);
        P.push_back(p);
        curr_maxl = L[0]+w;
        curr_maxh = H[0];
        int ln = w;
        long long int stable_p=0;
        long long int total_p=0;
        for(int i=1;i<n;i++){
            if(L[i]<=curr_maxl){
                curr_maxh = max(curr_maxh,H[i]);
                ln+=L[i]-L[i-1];
            }
            else{
                stable_p += p;
                curr_maxh=H[i];
                ln=w;
            }
            curr_maxl = L[i]+w;
            p = 2*(ln+curr_maxh);
            total_p = (p+stable_p)%1000000007;
            P.push_back(total_p);
        }
        long long int ans=1;
        for(int i=0;i<P.size();i++){
            ans = (ans*P[i])%1000000007;
        }
        // for(auto x:P){cout<<x<<" ";}
        cout<<"Case #"<<t<<":"<<ans%1000000007;
    }
    return 0;
}