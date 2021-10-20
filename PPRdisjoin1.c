#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Disjoint_set{
    int n;
    int parent[100];
}Set;


Set* makeSet(int n){
    Set* t;
    t->n = n;
    for(int i=0;i<n;i++){
        (t->parent)[i] = i;
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
void Union(int x, int y, Set *t){    //Quick Union operation
    int xset = Find(x,t);
    int yset = Find(y,t);
    if(xset == yset){
        return;
    }
    else if(xset>yset){
        (t->parent)[xset] = yset;
    }
    else{
        (t->parent)[yset] = xset;
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
    int n=7;
    // cin>>n;
    
    //Make set operation
    Set d = *(makeSet(n));

    //Union operation
    Union(0,1,&d);
    Union(1,2,&d);
    Union(5,6,&d);

    printf("Find of all the values in the set are:\n");
    for(int i=0;i<n;i++){
        printf("Find(%d) is %d\n",i,Find(i,&d));
    }

    // Print the disjoint sets

    printf("The disjoint sets are:\n");
    print_forest(d);
    return 0;
}