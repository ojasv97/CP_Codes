#include<bits/stdc++.h>
using namespace std;
class gen_tree{
    public:
    char val;
    vector<gen_tree*> child;
    gen_tree(char val,int n){
        this->val=val;
    }
    void inorder_gentree(gen_tree *root){
        if(root->child.size()!=0){
            for(int i=0;i<root->child.size()-1;i++){
                inorder_gentree(root->child[i]);
            }
            cout<<root->val<<" ";
            inorder_gentree(root->child[root->child.size()-1]);
        }
        else{
            cout<<root->val<<" ";
        }
    }
    void inorder_bintree(gen_tree* root){
        if(root==nullptr){
            return;
        }
        gen_tree* left = nullptr;
        gen_tree* right = nullptr;
        if(root->child.size()>0){
            if(root->child.size()==1){
                left = root->child[0];
            }
            else{
                left = root->child[0];
                right = root->child[1];
            }
        }
        inorder_bintree(left);
        cout<<root->val<<" ";
        inorder_bintree(right);
    }
    void convert(gen_tree* root){
        gen_tree* temp;
        if(root->child.size()!=0){
            convert(root->child[0]);
            temp=root->child[0];
        }
        else{
            return;
        }
        while(root->child.size()>=2){
            convert(root->child[1]);
            if(temp->child.size()==1){
                temp->child.push_back(root->child[1]);
            }
            else{
                temp->child.push_back(nullptr);
                temp->child.push_back(root->child[1]);
            }
            temp = root->child[1];
            root->child.erase(root->child.begin()+1);
        }
    }
};
int main(){
    gen_tree* root = nullptr;
    root = new gen_tree('a',4);
    root->child.push_back(new gen_tree('b',2));
    root->child.push_back(new gen_tree('c',0));
    root->child.push_back(new gen_tree('d',3));
    root->child.push_back(new gen_tree('e',0));
    root->child[0]->child.push_back(new gen_tree('f',0));
    root->child[0]->child.push_back(new gen_tree('g',0));
    root->child[2]->child.push_back(new gen_tree('h',0));
    root->child[2]->child.push_back(new gen_tree('i',0));
    root->child[2]->child.push_back(new gen_tree('j',0));
    root->inorder_gentree(root);
    root->convert(root);
    cout<<"\n";
    root->inorder_bintree(root);
    return 0;
}