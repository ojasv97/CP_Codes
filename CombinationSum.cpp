// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

void solve(vector<int> &A, int sm, vector<int> curr, vector<vector<int>> &ans, int ind, int B){
    cout<<ind<<endl;
    if(ind==A.size()){
        if(sm==B){
            sort(curr.begin(),curr.end());
            for(auto it:ans){
                if(it==curr){
                    return;
                }
            }
            ans.push_back(curr);
            
        }
        return;
    }
    if(A[ind]>B - sm){
        solve(A,sm,curr,ans,ind+1,B);
    }
    else{
        sm+=A[ind];
        curr.push_back(A[ind]);
        solve(A,sm,curr,ans,ind,B);
        curr.pop_back();
        sm-=A[ind];
        solve(A,sm,curr,ans,ind+1,B);
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Your code here
    vector<vector<int>> ans;
    int sm=0;
    vector<int> curr;
    solve(A,sm,curr,ans,0,B);
    sort(ans.begin(),ans.end());
    return ans;
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends