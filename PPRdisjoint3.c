#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Disjoint_set{
    int n;
    int parent[100];
    int rank[100]; //Rank matrix to store the upper bound of height of a tree.
}Set;


Set* makeSet(int n){
    Set* t;
    t->n = n;
    for(int i=0;i<n;i++){
        (t->parent)[i] = i;
        (t->rank)[i] = 0;
    }
    return t;
}

int Find(int x, Set* t){   //Find operation
    if (t->parent[x]!=x){
        return Find(t->parent[x], t);
    }
    else{
        return t->parent[x];
    }
}

void Union_by_rank(int x, int y, Set* t){    //Union by Rank
    int xset = Find(x,t);
    int yset = Find(y,t);

    if(xset == yset){
        return;
    }
    if (t->rank[xset] < t->rank[yset]){
        (t->parent)[xset] = yset;
    } 
    else if (t->rank[xset] > t->rank[yset]){ 
        (t->parent)[yset] = xset; 
    } 
    else { 
        t->parent[yset] = xset;
        t->rank[xset] = t->rank[xset] + 1; 
    }
    return;
}

void print_forest(Set t){
    int check[100];
    for(int i=0;i<t.n;i++){
        check[i]=0;
    }
    for(int i=0;i<t.n;i++){
        check[Find(i,&t)]=1;
    }
    for(int i=0;i<t.n;i++){
        if(check[i]==1){
            printf("%d",i);
            for(int j=0;j<t.n;j++){
                if(Find(j,&t)==i && j!=i){
                    printf("--%d",j);
                }
            }
            printf("\n");
        }
    }
}
int main(){
    int k=11;
    
    //Make set operation
    Set d = *(makeSet(k));

    //Union operation
    Union_by_rank(0,1,&d);
    Union_by_rank(0,4,&d);
    Union_by_rank(1,2,&d);
    Union_by_rank(5,6,&d);
    Union_by_rank(4,5,&d);

    printf("Find of all the values in the set are:\n");
    for(int i=0;i<k;i++){
        printf("Find(%d) is %d\n",i,Find(i,&d));
    }
    
    // Print the disjoint sets

    printf("\nThe disjoint sets are:\n");
    print_forest(d);
    return 0;
}