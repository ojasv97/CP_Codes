#include <bits/stdc++.h>
using namespace std;
void check(int ind, vector<string>&wordDict, string &s, string st, vector<string> &ans){
    if(ind>s.length()){
        return;
    }
    if(ind==s.length()){
        ans.push_back(st);
        return;
    }
    for(int i=0;i<wordDict.size();i++){
        int l = wordDict[i].length();
        
        if(ind+l<=s.length() && s.substr(ind,l) == wordDict[i]){
            if(st.length()!=0){
                st.push_back(' ');
            }
            st.append(s.substr(ind,l));
            check(ind+l,wordDict,s,st,ans);
            st.erase(st.begin()+st.length()-l,st.end());
            if(st.length()!=0){
                st.pop_back();
            }
            
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> wordDict;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            wordDict.push_back(s);
        }
        vector<string> ans;
        cin>>s;
        check(0,wordDict,s,"",ans);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
    }
	//code
	return 0;
}