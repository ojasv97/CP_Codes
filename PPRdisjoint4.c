#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Disjoint_set{
    int n;
    int parent[20];
    int rank[20]; //Rank matrix to store the upper bound of height of a tree.
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


int FindSet_WITH_PathCompression(int x, Set* t){   //Find operation with path compression
    if (t->parent[x]!=x){
        t->parent[x]=FindSet_WITH_PathCompression(t->parent[x], t);  //Path Comprression
        t->rank[x]=0;
    }
    else{
        return t->parent[x];
    }
    return t->parent[x];
}

int FindSet_WITHOUT_PathCompression(int x, Set* t){   //Find operation without path compression
    if (t->parent[x]!=x){
        return FindSet_WITHOUT_PathCompression(t->parent[x], t);
    }
    else{
        return t->parent[x];
    }
    return t->parent[x];
}

void UnionByRankPATHCOMPRESSION(int x, int y, Set* t){    //Union by Rank
    int xset = FindSet_WITH_PathCompression(x,t);
    int yset = FindSet_WITH_PathCompression(y,t);
    t->rank[xset]=1;
    t->rank[yset]=1;

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
void UnionByRankNOPATHCOMPRESSION(int x, int y, Set* t){    //Union by Rank
    int xset = FindSet_WITHOUT_PathCompression(x,t);
    int yset = FindSet_WITHOUT_PathCompression(y,t);

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
        check[FindSet_WITHOUT_PathCompression(i,&t)]=1;
    }
    for(int i=0;i<t.n;i++){
        if(check[i]==1){
            printf("%d",i);
            for(int j=0;j<t.n;j++){
                if(FindSet_WITHOUT_PathCompression(j,&t)==i && j!=i){
                    printf("--%d",j);
                }
            }
            printf("\n");
        }
    }
}
int main(){
    int k=12;
    //Make set operation
    Set* d = makeSet(k);
    //Union operation on Set d(PATH COMPRESSION)
    UnionByRankPATHCOMPRESSION(0,1,d);
    UnionByRankPATHCOMPRESSION(2,3,d);
    UnionByRankPATHCOMPRESSION(4,5,d);
    UnionByRankPATHCOMPRESSION(6,7,d);
    UnionByRankPATHCOMPRESSION(0,2,d);
    UnionByRankPATHCOMPRESSION(4,7,d);
    UnionByRankPATHCOMPRESSION(0,4,d);
    UnionByRankNOPATHCOMPRESSION(9,11,d);
    printf("The height of each element in the tree with PATH COMPRESSION\n");
    for(int i=0;i<k;i++){
        printf("%d ",d->rank[i]); 
    }

    printf("\n");

    //Union operation on Set q(NO PATH COMPRESSION)
    Set* q = makeSet(k);

    UnionByRankNOPATHCOMPRESSION(0,1,q);
    UnionByRankNOPATHCOMPRESSION(2,3,q);
    UnionByRankNOPATHCOMPRESSION(4,5,q);
    UnionByRankNOPATHCOMPRESSION(6,7,q);
    UnionByRankNOPATHCOMPRESSION(0,2,q);
    UnionByRankNOPATHCOMPRESSION(4,7,q);
    UnionByRankNOPATHCOMPRESSION(0,4,q);
    UnionByRankNOPATHCOMPRESSION(9,11,q);

    printf("The height of each element in the tree with NO PATH COMPRESSION\n");
    for(int i=0;i<k;i++){
        printf("%d ",q->rank[i]); 
    }
    
    printf("\n");
    printf("Printing the whole forest\n");
    print_forest(*d);
    return 0;
}