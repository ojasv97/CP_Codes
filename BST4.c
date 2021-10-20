#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void insert(node** root,int val){
    if(*root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->data=val;
        temp->left=NULL;
        temp->right=NULL;
        *root = temp;
    }
    else if((*root)->data>val){
        insert(&((*root)->left),val);
    }
    else if((*root)->data<val){
        insert(&((*root)->right),val);
    }
}
void print_paths(node* root, int** arr, int n, int* count){
    int* a = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++){
        a[i]=(*arr)[i];
    }
    a[n]=root->data;
    int n1 = n+1;
    if(!root->left && !root->right){
        *count=*count+1;
        printf("Path %d ---  ",*count);
        for(int i=0;i<n1;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else if(!root->right){
        print_paths(root->left,&a,n1,count);
    }
    else if(!root->left){
        print_paths(root->right,&a,n1,count);
    }
    else{
        print_paths(root->left,&a,n1,count);
        print_paths(root->right,&a,n1,count);
    }
}
int main(){
    int i=0;
    node* root = NULL;
	int arr[100];
	char sep;
    printf("Enter the elements of the tree as space seperated integers.\n");
	while(scanf("%d%c",&arr[i],&sep)){
        i++;
        if(sep!=' ')
            break;
    }
    for(int j=0;j<i;j++){
        insert(&root,arr[j]);
    }
    int* a;
    int count=0;
    print_paths(root,&a,0,&count);
}