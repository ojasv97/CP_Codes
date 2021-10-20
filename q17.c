#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
typedef struct node node;
void insert(node** root,int data){
    if(*root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        *root = temp;
    }
    else if((*root)->data>data){
        insert(&((*root)->left),data);
    }
    else if((*root)->data<data){
        insert(&((*root)->right),data);
    }
}
void level_order(node* root,node** visited,int* pos)
{
    if(root==NULL)
    return;
    printf("%d ",root->data);
    if(root->left!=NULL)
    {
        visited[*pos]=root->left;
        *pos=*pos+1;
       
    }
    if(root->right!=NULL)
    {
        visited[*pos]=root->right;
        *pos=*pos+1;
        
    }

}
void BFS(node* root,node** visited,int size)
{
    if(root==NULL)
    return;
    visited[0]=root;
    int i=0;
    int pos=1;
    for(i=0;i<size;i++)    
       level_order(visited[i],visited,&pos);
    
    printf("\n");
}
int main()
{
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
    node* visit = (node*)malloc(sizeof(node)*i);
    node** visited = &visit;
    printf("\nThe BFS traversal is:\n");
    BFS(root,visited,i);
}