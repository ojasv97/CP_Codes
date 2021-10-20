#include<bits/stdc++.h>
using namespace std;
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
void primeFactors(int n, vector<int> &ans)
{
    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        ans.push_back(n);
}
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        vector<int> B;
        A.push_back(1);
        for(int i=2;i<=n;i++){
            if(gcd(i,n)==1){
                A.push_back(i);
                if(n%i==)
            }
        }

    }
}