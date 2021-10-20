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
int main(){
    int arr[100];
    int n;
    int size=0;
    int v;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&v);
        insert(arr,&size,v);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}