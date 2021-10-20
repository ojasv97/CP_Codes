#include<bits/stdc++.h>
using namespace std;
vector<int> primeFactors(int n)
{
    vector<int> s;
    while (n % 2 == 0) {
        s.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            s.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        s.push_back(n);
    sort(s.begin(),s.end());
    return s;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        vector<int> s = primeFactors(n);
        while(s.size()>=p){
            int k = 1;
            int v = 0;
            
            for(auto it: s){
                if(k==p){
                    v = it;
                    break;
                }
                k++;
            }
            n = n - v;
            if(n==0){
                break;
            }
            s = primeFactors(n);
        }
        cout<<n<<endl;
    }
    return 0;
}