#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
bool isDivisible(string &a, string &b){
    if(a.length()>b.length()){
        if(a.length()%b.length()!=0){
            return false;
        }
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i%b.length()]){
                return false;
            }
        }
    }
    else{
        if(b.length()%a.length()!=0){
            return false;
        }
        for(int i=0;i<b.length();i++){
            if(b[i]!=a[i%a.length()]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s1.length();i++){
            if(mp1.find(s1[i])!=mp1.end()){
                mp1[s1[i]]++;
            }
            else{
                mp1[s1[i]]=1;
            }
        }
        for(int i=0;i<s2.length();i++){
            if(mp2.find(s2[i])!=mp2.end()){
                mp2[s2[i]]++;
            }
            else{
                mp2[s2[i]]=1;
            }
        }
        if(mp1.size()!=mp2.size()){cout<<-1<<endl;}
        else{
            if(mp1.size()==1){
                int c1 = mp1[s1[0]];
                int c2 = mp2[s2[0]];
                int y = lcm(c1,c2);
                string s="";
                for(int i=0;i<y;i++){s+=s1[0];}
                cout<<s<<endl;
            }
            else{
                if(isDivisible(s1,s2)){
                    if(s1.length()>s2.length()){
                        cout<<s1<<endl;
                    }
                    else{
                        cout<<s2<<endl;
                    }
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
    }
    return 0;
}   