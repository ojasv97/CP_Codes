#include<bits/stdc++.h>
using namespace std;
class tree{
    public:
    int val;
    tree *left,*right;
    tree(int val){
        this->val=val;
        this->left = NULL;
        this->right = NULL;
    }
    void inorder(tree *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
    }
    bool BST(tree *root, int mn, int mx){
        if(root->val<=mn || root->val>=mx){
            return false;
        }
        bool x=true;
        bool y=true;
        if(root==NULL){
            return true;
        }
        if(root->left!=NULL){
            int mx_=min(mx,root->val);
            x = BST(root->left,mn,mx_);
        }
        if(root->right!=NULL){
            int mn_=max(mn,root->val);
            y = BST(root->right,mn_,mx);
        }
        return x&y;
    }
};
int main(){
    tree *node1 = new tree(23);
    tree *node2 = new tree(17);
    tree *node3 = new tree(32);
    tree *node4 = new tree(8);
    tree *node5 = new tree(20);
    tree *node6 = new tree(27);
    tree *node7 = new tree(30);
    node1->left = node2;
    node1->right = node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    node3->right=node7;
    bool res;
    res = node1->BST(node1, INT_MIN, INT_MAX);
    cout<<res<<endl;
    return 0;
}