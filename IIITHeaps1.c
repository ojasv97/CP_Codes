#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

void swap(int* i, int* j){
    int* temp;
    *temp = *i;
    *i = *j;
    *j = *temp;
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
            if(arr[(j-1)/2]>val){
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
void adjust(int* arr,int *size){
    int item = arr[0];
    int j = 0;
    int i = 1;
    while(i<*size){
        if(arr[i]>arr[i+1]){
            i = i+1;
        }
        if(arr[i]<arr[j]){
            printf(" ");
            swap(&arr[i], &arr[j]);
            j = i;
            i = 2*i+1;
        }
        else{
            break;
        }
    }
}
int delete(int* arr,int* size){
    int val;
    if(*size==0){
        printf("No elements in the heap\n");
    }
    else{
        val = arr[0];
        arr[0]=arr[*size-1];
        *size = *size-1;
        adjust(arr,size);
    }
    return val;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int arr[100];
        int n,k;
        int size=0;
        scanf("%d %d",&n,&k);
        int v;
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            insert(arr,&size,v);
        }
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        int p;
        for(int i=0;i<k;i++){
            int p = delete(arr,&size);
            printf("\n%d\n",p);
            for(int i=0;i<size;i++){
                printf("%d ",arr[i]);
            }
        }
    //     p = delete(arr,&size);
    //     printf("\n%d\n",p);
    //     for(int i=0;i<size;i++){
    //         printf("%d ",arr[i]);
    //     }
    }
    return 0;
}