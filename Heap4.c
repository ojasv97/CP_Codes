#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}node;
void inorder(node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void levelorder(node* root,int* size){
    node** queue = (node**)malloc(sizeof(node*)*(*size));
    int i=0;
    queue[0] = root;
    if(*size==0){
        printf("Empty");
    }
    while(i<*size){
        if(queue[i]->left!=NULL){
            queue[2*i+1]=queue[i]->left;
        }
        if(queue[i]->right!=NULL){
            queue[2*i+2]=queue[i]->right;
        }
        printf("%d ",queue[i]->data);
        i++;
    }
}
void swap(int* i, int* j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
node* position_newnode(node* root,int *size){
    node** queue = (node**)malloc(sizeof(node*)*(*size));
    int i=0;
    queue[0] = root;
    while(i<*size){
        if(queue[i]->left!=NULL){
            queue[2*i+1]=queue[i]->left;
        }
        else{
            return queue[i];
        }
        if(queue[i]->right!=NULL){
            queue[2*i+2]=queue[i]->right;
        }
        else{
            return queue[i];
        }
        i++;
    }
    return root;
}
void adjust(node* root){
    int val = root->data;
    node* p1 = root;
    node* p2 = root->left;
    while(p2!=NULL){
        if(p1->right!=NULL && p1->left->data>p1->right->data){
            p2=p1->right;
        }
        if(p2->data<p1->data){
            swap(&(p2->data), &(p1->data));
            p1 = p2;
            p2 = p2->left;
        }
        else{
            break;
        }
    }
}
node* lastnode(node* root,int *size){
    node** queue = (node**)malloc(sizeof(node*)*(*size));
    int i=0;
    queue[0] = root;
    while(i<*size){
        if(queue[i]->left!=NULL){
            queue[2*i+1]=queue[i]->left;
        }
        if(queue[i]->right!=NULL){
            queue[2*i+2]=queue[i]->right;
        }
        i++;
    }
    return queue[(*size)-1];
}
void delete_min(node** root,int* size){ 
    if(*size==1){
        *root=NULL;
        *size=*size-1;
        return;
    }
    node* temp = lastnode(*root,size);
    swap(&(temp->data),&((*root)->data));
    *size=*size-1;
    if(temp->parent->left==temp){
        temp->parent->left = NULL;
    }
    else{
        temp->parent->right=NULL;
    }
    free(temp);
    temp=NULL;
    adjust(*root);
}
void insert(node** root,int val, int* size, int max_size){
    if(max_size==*size){
        printf("Overflow\n");
        return;
    }
    if(*root==NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->data=val;
        temp->parent=NULL;
        temp->left=NULL;
        temp->right=NULL;
        *size=*size+1;
        *root = temp;
        return;
    }
    else{
        node* temp = position_newnode(*root,size);
        if(temp->left==NULL){
            temp->left=(node*)malloc(sizeof(node));
            temp->left->data=val;
            temp->left->left=NULL;
            temp->left->right=NULL;
            temp->left->parent=temp;
            *size=*size+1;
            node* t = temp->left;
            while(t->parent!=NULL){
                if(val<t->parent->data){
                    t->data = t->parent->data;
                    t = t->parent;
                }
                else{
                    break;
                }
            }
            t->data = val;
        }
        else{
            temp->right=(node*)malloc(sizeof(node));
            temp->right->data=val;
            temp->right->left=NULL;
            temp->right->right=NULL;
            temp->right->parent=temp;
            *size=*size+1;
            node* t = temp->right;
            while(t->parent!=NULL){
                if(val<t->parent->data){
                    t->data = t->parent->data;
                    t = t->parent;
                }
                else{
                    break;
                }
            }
            t->data = val;
        }

    }
}
void checkEmpty(node* root){
    if(root==NULL){
        printf("True\n");
    }
    else{
        printf("False\n");        
    }
}
void checkFull(int* size,int max_size){
    if(*size==max_size){
        printf("True\n");
    }
    else{
        printf("False\n");        
    }
}
int main(){
    //Considering maximum size to be 10 elements.
    int max_size=10;
    int n;
    int v;
    scanf("%d",&n);
    node* root = NULL;
    int size=0;
    int choice;
    while(scanf("%d",&choice)==1){
        switch (choice)
        {
        case 1:
            scanf("%d",&v);
            insert(&root,v,&size,max_size);
            levelorder(root,&size);
            printf("\n");
            break;
        case 2:
            if(size!=0){
                delete_min(&root,&size);
                levelorder(root,&size);
                printf("\n");
            }
            else{
                printf("Underflow\n");
            }
            break;
        case 3:
            checkFull(&size,max_size);
            break;
        case 4:
            checkEmpty(root);
            break;
        case 5:
            break;
        default:
            break;
        }
        if(choice==5){
            break;
        }
    }
    return 0;
}