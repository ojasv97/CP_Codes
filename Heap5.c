#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

void swap(int* i, int* j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
void adjust(int* arr,int *size, int ind, int* exchanges){    

    int item = arr[ind];
    int j = ind;
    int i = 2*ind+1;
    while(i<*size){
        if(i+1<*size && arr[i]<arr[i+1]){
            i = i+1;
        }
        if(arr[i]>arr[j]){
            swap(&arr[i], &arr[j]);
            *exchanges = *exchanges+1;
            j = i;
            i = 2*i+1;
        }
        else{
            break;
        }
    }
}
void build_heap_bottomup(int* arr, int* size, int* exchanges){
    int n = *size;
    for(int i=(n/2)-1;i>=0;i--){
        adjust(arr,size,i,exchanges);
    }
}
void insert_topdown(int* arr, int *size, int val, int* exchanges){
    if(*size==0){
        arr[0]=val;
        *size = *size+1;
        return;
    }
    else{
        int j=*size;
        while(j>0){
            if(arr[(j-1)/2]<val){
                *exchanges=*exchanges+1;
                arr[j] = arr[(j-1)/2];
                j=(j-1)/2;
            }
            else{
                break;
            }
        }
        *size = *size+1;
        arr[j] = val;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    int a=0;
    while(T--){
        a++;
        int arr[100];
        int arr2[100];
        int n;
        int v;
        int size=0;
        scanf("%d",&n);
        int exchanges_topdown = 0;
        int exchanges_bottomup = 0;

        for(int i=0;i<n;i++){
            scanf("%d",&v);
            insert_topdown(arr,&size,v,&exchanges_topdown);
            arr2[i]=v;
        }
        build_heap_bottomup(arr2,&n,&exchanges_bottomup);
        printf("\n");
        printf("For array %d the output is:   ",a);
        exchanges_bottomup<exchanges_topdown?printf("%d\n",exchanges_bottomup):printf("%d\n",exchanges_topdown);
        printf("\n\n");
    }
    return 0;
}