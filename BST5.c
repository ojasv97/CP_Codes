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
void count_leaves(node* root, int* count){
    if(root->left==NULL && root->right==NULL){
        *count=*count+1;
        return;
    }
    if(root->left!=NULL){
        count_leaves(root->left,count);
    }
    if(root->right!=NULL){
        count_leaves(root->right,count);
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
    int count=0;
    count_leaves(root,&count);
    printf("Number of leaves = %d.\n",count);
}