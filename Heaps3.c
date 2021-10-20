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
void insert(int* arr, int *size, int val){
    if(*size==0){
        arr[0]=val;
        *size = *size+1;
        return;
    }
    else{
        int j=*size;
        while(j>0){
            if(arr[(j-1)/2]<val){
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
void adjust(int* arr,int *size, int ind){    
    int item = arr[ind];
    int j = ind;
    int i = 2*ind+1;
    while(i<*size){
        if(arr[i]<arr[i+1]){
            i = i+1;
        }
        if(arr[i]>arr[j]){
            swap(&arr[i], &arr[j]);
            j = i;
            i = 2*i+1;
        }
        else{
            break;
        }
    }
}
int delete_root(int* arr,int* size){
    int val;
    if(*size==0){
        printf("No elements in the heap\n");
    }
    else{
        val = arr[0];
        arr[0]=arr[*size-1];
        *size = *size-1;
        adjust(arr,size,0);
    }
    return val;
}
void build_heap_bottomup(int* arr, int* size){
    int n = *size;
    for(int i=n/2-1;i>=0;i--){
        adjust(arr,size,i);
    }
}

void heapsort(int* arr, int* size){
    int mx;
    int s = *size;
    while(s!=1){
        mx=delete_root(arr,&s);
        arr[s] = mx;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    int a=0;
    while(T--){
        a++;
        int arr[100];
        int n;
        int size=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            size++;
        }
        build_heap_bottomup(arr,&size);
        heapsort(arr,&size);
        printf("For array %d the output is:   ",a);
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n\n");
    }
    return 0;
}