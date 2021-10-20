// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool isKPartitionPossible(int [], int , int );

 
//  Driver code to test above methods
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	cout<<isKPartitionPossible(a, n, k)<<endl;
    }
}// } Driver Code Ends


/*You are required to complete this method */
int solve(vector<int> &a,vector<int> &vis, int i, set<vector<int>> &sub, int k, int cs,vector<int> c_sub){
    if(i>=a.size()){
        return 0;
    }
    int v = 0;
    if(a[i]==k-cs){
        int t=0;
        c_sub.push_back(a[i]);
        sub.insert(c_sub);
        vis[i]=1;
        for(int j=0;j<=i;j++){
            if(vis[i]==0){
                t=1;
            }
        }
        if(t==0 && i-1<a.size()){
            c_sub.clear();
            solve(a,vis,i+1,sub,k,0,c_sub);
        }
        return 1;
    }
    if(vis[i]){
        v = solve(a,vis,i+1,sub,k,cs,c_sub);
    }
    else{
        cs = cs+a[i];
        if(cs>k){
            return v;
        }
        c_sub.push_back(a[i]);
        v = solve(a,vis,i+1,sub,k,cs,c_sub);
        if(v){
            cs = 0;
            c_sub.clear();
        }
        else{
            cs = cs-a[i];
            c_sub.pop_back();
        }
        v = solve(a,vis,i+1,sub,k,cs,c_sub);
    }
    return v;
}

bool isKPartitionPossible(int a[],int n, int k){
    vector<int> v(n,0);
    int sm=0;
    for(int i=0;i<n;i++){
        v[i] = a[i];
        sm+=v[i];
    }
    int sbs;
    if(sm%k==0){
        sbs = sm/k;
    }
    else{
        return false;
    }
    set<vector<int>> ans;
    vector<int> vis(n,0);
    int cs = 0;
    vector<int> c_sub;
    int q  = solve(v,vis,0,ans,sbs,cs,c_sub);
    // for(auto it: ans){
    //     for(int j=0;j<it.size();j++){
    //         cout<<it[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(ans.size()==k){
        return true;
    }
    return false;
}