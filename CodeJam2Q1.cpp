#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                if(arr[i]==arr[i-1]){
                    arr[i]++;
                }
                else{
                    string s1 = to_string(arr[i-1]);
                    string s2 = to_string(arr[i]);
                    string s1a = s1.substr(s2.length());
                    string s1b = s1.substr(0,s2.length());
                    int a = stoi(s1a);
                    int b = stoi(s1b);
                    if(a==arr[i]){
                        string c = to_string(b+1);
                        cnt+=c.length();
                        if(c.length()>s2.length()){
                            c[0]='0';
                            s2 = s2+c;
                            arr[i]=stoi(s2);
                        }
                        else{
                            s2=s2+c;
                            arr[i]=stoi(s2);
                        }
                    }
                    else if(a<arr[i]){
                        string c = "";
                        for(int j=0;j<s1b.length();j++){
                            cnt++;
                            c+='0';
                        }
                        s2=s2+c;
                        arr[i]=stoi(s2);
                    }
                    else{
                        string c="";
                        for(int j=0;j<=s1b.length();j++){
                            c+='0';
                            cnt++;
                        }
                        s2=s2+c;
                        arr[i]=stoi(s2);
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}