#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n]={0};
        int n_1=0;
        int n_0=0;
        int k = n/2;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                n_1++;
            }
            else{
                n_0++;
            }
        }
        if(n==2){
            if(arr[0]==1 && arr[1]==0){
                printf("0");
                return 0;
            }
            else if(arr[0]==0 && arr[1]==0){
                printf("0");
                return 0;
            }    
        }
        if(n_1>n_0){
            if(k%2!=0){k++;}
            printf("%d\n",k);
            for(int i=0;i<k;i++){
                printf("1 ");
            }
        }
        else{
            printf("%d\n",k);
            for(int i=0;i<k;i++){
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}

