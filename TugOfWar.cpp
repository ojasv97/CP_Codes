#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>l1, vector<int>l2, int s1, int s2, vector<int>& arr, int i, int& mn, int& sm, vector<int>&out){
    if(l1.size()>(arr.size()/2)+1 || l2.size()>(arr.size()/2)+1){
        return;
    }
    l1.push_back(arr[i]);
    s1+=arr[i];
    if(i==arr.size()-1){
        if(arr.size()%2==0 && l1.size()-l2.size()==0){
            if(mn>abs(s1-s2)){
                out = l1;
                mn = abs(s1-s2);
                sm = s1;
            }
            return;
        }
        if(arr.size()%2==1 && (l1.size()-l2.size()==1 || l1.size()-l2.size()==-1)){
            if(mn>abs(s1-s2)){
                out=l1;
                mn = abs(s1-s2);
                sm = s1;
            }
            return;
        }
    }
    solve(l1,l2,s1,s2,arr,i+1,mn,sm,out);
    s1-=arr[i];
    l1.pop_back();
    l2.push_back(arr[i]);
    s2+=arr[i];
    if(i==arr.size()-1){
        if(arr.size()%2==0 && l1.size()-l2.size()==0){
            if(mn>abs(s1-s2)){
                out=l1;
                mn = abs(s1-s2);
                sm = s1;
            }
            return;
        }
        if(arr.size()%2==1 && (l1.size()-l2.size()==1 || l1.size()-l2.size()==-1)){
            if(mn>abs(s1-s2)){
                out=l1;
                mn = abs(s1-s2);
                sm = s1;
            }
            return;
        }
    }
    solve(l1,l2,s1,s2,arr,i+1,mn,sm,out);
    s2-=arr[i];
    l2.pop_back();
}

int main(){
    vector<int> a;
    int t;
    while(cin.peek()!='\n'){
        cin>>t;
        a.push_back(t);
    }
    vector<int> l1;
    vector<int> l2;
    int s1=0;
    int s2=0;
    vector<int> ans;
    int mn = INT_MAX;
    int sm = INT_MIN;
    solve(l1,l2,s1,s2,a,0,mn,sm,ans);
    for(auto it: ans){
        cout<<it<<" ";
    }
}