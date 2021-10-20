#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int k=t;
    while(t--){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int mn_cost = 0;
        char p = 'A';
        for(int i=0;i<s.length();i++){
            if(s[i]=='C'){
                if(p=='J'){
                    mn_cost+=y;
                }
                p=s[i];
            }
            else if(s[i]=='J'){
                if(p=='C'){
                    mn_cost+=x;
                }
                p=s[i];
            }
        }
        cout<<"Case #"<<k-t<<": "<<mn_cost<<endl;
    }
    return 0;
}