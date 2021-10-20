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
void adjust(int* arr,int *size){    
    int item = arr[0];
    int j = 0;
    int i = 1;
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
        adjust(arr,size);
    }
    return val;
}
void delete_element(int* arr,int* size, int val){
    int j=-1;
    for(int i=0;i<*size;i++){
        if(arr[i]==val){
            j = i;
            break;
        }
    }
    if(j==-1){
        printf("%d not found\n",val);
    }
    else{
        int s = *size - j;
        delete_root(arr+j,&s);
        *size=*size-1;
        printf("Deleted\n");
    }
}
int main(){
    int heap[100];
    char choice;
    int val;
    int size=0;
    while(scanf("%c",&choice)==1){
        switch (choice)
        {
        case 'a':
            scanf("%d",&val);
            insert(heap,&size,val);
            printf("Inserted\n");          
            break;
        case 'b':
            scanf("%d",&val);
            delete_element(heap,&size,val);
            break;
        case 'c':
            for(int i=0;i<size;i++){
                printf("%d ",heap[i]);
            }
            printf("\n");
            break;
        case 'd':
            break;
        default:
            break;
        }
        if(choice=='d'){
            break;
        }
    }
    return 0;
}