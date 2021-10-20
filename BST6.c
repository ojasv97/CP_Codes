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
void sum_leaves(node* root, int* sum){
    if(root->left==NULL && root->right==NULL){
        *sum=*sum+root->data;
        return;
    }
    if(root->left!=NULL){
        sum_leaves(root->left,sum);
    }
    if(root->right!=NULL){
        sum_leaves(root->right,sum);
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
    int sum=0;
    sum_leaves(root,&sum);
    printf("Sum of leaf node = %d.\n",sum);
    return 0;
}