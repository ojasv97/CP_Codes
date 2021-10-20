#include<bits/stdc++.h>
using namespace std;





//Constructing tree from given preorder and inorder
class tree{
    private:
    int val;
    tree *left,*right;
    public:
    tree(int val){
        this->val=val;
        this->left = NULL;
        this->right = NULL;
    }
    tree *insert(tree *root,int val){

        //create_treetion to create BST.

        if(root==NULL){
            return new tree(val);
        }
        if(root->val<val){
            root->right = insert(root->right,val);
        }
        else{
            root->left = insert(root->left,val);
        }
        return root;
    }
    void inorder(tree *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
    }
    tree* create_tree(int &idx,int st,int en,int *pre ,unordered_map<int,int> &m){
        if(st>en){return nullptr;}
        tree *node = new tree(pre[idx]);
        int id = m[pre[idx]];
        idx++;
        node->left = create_tree(idx,st,id-1,pre,m);
        node->right = create_tree(idx ,id+1,en,pre,m);
        return node;
    }
};
int main(){
    int in[] = {0,1,2,3,4,5};
    int pre[]={0,2,1,5,4,3};
    unordered_map<int,int> m;
    for(int i=0;i<6;i++){
        m[in[i]]=i;
    }
    int pre_idx = 0;
    tree *root=NULL; 
    root = root->create_tree(pre_idx,0,5,pre,m);
    // tree *root = new tree(7);
    // root = root->insert(root,8);
    // root = root->insert(root,9);
    // root = root->insert(root,2);
    // root = root->insert(root,5);
    root->inorder(root);
    return 0;
}