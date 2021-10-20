#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

void makeSet(int n, int* parent, int* rank){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(int x, int* parent){   //Find operation
    if (parent[x]!=x){
        return Find(parent[x], parent);
    }
    else{
        return parent[x];
    }
}

void Union_by_rank(int x, int y, int* parent, int* rank){    //Union by Rank
    int xset = Find(x,parent);
    int yset = Find(y,parent);

    if(xset == yset){
        return;
    }
    if (rank[xset] < rank[yset]){
        parent[xset] = yset;
    } 
    else if (rank[xset] > rank[yset]){ 
        parent[yset] = xset; 
    } 
    else { 
        parent[yset] = xset;
        rank[xset] = rank[xset] + 1; 
    }
    return;
}

void print_forest(int n, int* parent){
    int check[100];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    for(int i=0;i<n;i++){
        check[Find(i,parent)]=1;
    }
    for(int i=0;i<n;i++){
        if(check[i]==1){
            printf("%d",i);
            for(int j=0;j<n;j++){
                if(Find(j,parent)==i && j!=i){
                    printf("--%d",j);
                }
            }
            printf("\n");
        }
    }
}
void connected_components(int n, int* parent){
    int* check = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    for(int i=0;i<n;i++){
        check[Find(i,parent)]=1;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(check[i]==1){
            count++;
        }
    }
    if(count==1){
        printf("Connected\n");
    }
    else{
        printf("Disonnected\n");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int* parent = (int*)malloc(sizeof(int)*n);
        int* rank = (int*)malloc(sizeof(int)*n);
        makeSet(n,parent,rank);
        int val;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&val);
                if(val==1){
                    Union_by_rank(i,j,parent,rank);
                }
            }
        }
        connected_components(n,parent);
    }
    return 0;
}