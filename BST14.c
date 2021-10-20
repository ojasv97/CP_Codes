#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create_tree(int* arr, int n){
    node* root = (node*)malloc(sizeof(node));
    root->data=arr[0];
    root->left=NULL;
    root->right=NULL;
    node* temp;
    node** queue = (node**)malloc(sizeof(node*)*n);
    queue[0]=root;
    for(int i=0;i<(n/2);i++){
        temp = queue[i];
        int l = 2*i+1;
        int r = 2*i+2;
        node* temp1=NULL;
        node* temp2=NULL;
        if(l<n){
            temp1 = (node*)malloc(sizeof(node));
            temp1->data=arr[l];
            temp1->left=NULL;
            temp1->right=NULL;
            temp->left = temp1;
            queue[l]=temp1;
        }
        if(r<n){
            temp2 = (node*)malloc(sizeof(node));
            temp2->data=arr[r];
            temp2->left=NULL;
            temp2->right=NULL;
            temp->right = temp2;
            queue[r]=temp2;
        }
    }
    return root;
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int calcsum(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return root->data + calcsum(root->left)+calcsum(root->right);
    }
}

int sum_tree(node* root){
    int val,val1,val2;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    val1 = calcsum(root->left);
    val2 = calcsum(root->right);
    val = val1 + val2;
    if(val==root->data){
        int a=0,b=0;
        if(root->left!=NULL){
            a=sum_tree(root->left);
        }
        if(root->right!=NULL){
            b=sum_tree(root->right);
        }
        return a||b;
    }
    return 0 ;
}
int main(){
    int i=0;
	int arr[100];
    node* root;
	char sep;
    printf("Enter the elements of the tree as space seperated integers.\n");
	while(scanf("%d%c",&arr[i],&sep)){
        i++;
        if(sep!=' ')
            break;
    }
    root = create_tree(arr,i);
    int val = sum_tree(root);
    printf("%d",val);
}