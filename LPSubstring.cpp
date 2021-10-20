#include<bits/stdc++.h>
using namespace std;
// int lcs(vector<char> &s, vector<char> &t, int i, int j, int &mx, int &ind){
//     if(i==s.size()||j==t.size()){
//         return 0;
//     }
//     int p;
//     if(s[i]==s[j]){
//         p = 1 + lcs(s,t,i-1,j-1,mx,ind); 
//     }
//     p = max(p,max(lcs(s,t,i,j-1,mx,ind),lcs(s,t,i-1,j-1,mx,ind)));
//     if(p>mx){
//         mx = p;
//         ind = i;
//     }
//     return p;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        getline(cin,s);
        cout<<s;
    }
	return 0;
}