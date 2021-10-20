#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}
int maxLen(int arr[], int N)
{
    vector<int> a(N,0);
    for(int i=0;i<N;i++){
        if(arr[i]==0){a[i]=-1;}
        else{a[i]=1;}
    }
    for(int i=1;i<N;i++){
        a[i]+=a[i-1];
    }
    for(auto x:a){cout<<x<<" ";}
    if(abs(a[N-1])==N){
        return 0;
    }
    int diff=INT_MIN;
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<N;i++){
        if(m.find(a[i])==m.end()){
            m[a[i]].first = INT_MIN;
            m[a[i]].second = i;
        }
    }
    for(int i=N-1;i>=0;i--){
        if(m[a[i]].first==INT_MIN){
            m[a[i]].first=i;
        }
    }
    m[0].second=-1;
    for(int i=0;i<N;i++){
        diff = max(m[a[i]].first-m[a[i]].second,diff);
    }
    for(auto it:m){
        cout<<it.first<<"|";
        cout<<it.second.first<<" "<<it.second.second;
        cout<<endl;
    }
    cout<<endl;
    return diff;
}