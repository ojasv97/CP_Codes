#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int type;
    int data;
    int parameter;
    vector<node*> left_child;
    vector<node*> right_child;
    string decision;
    node(string decision){
        this->type = 2;
    }
    node(int data){
        this->type = 1;
    }
};
class decision_tree{
    public:
    void inorder(node *root){
        if(root->left_child.size()!=0){
            for(int i=0;i<root->left_child.size()-1;i++){
                inorder(root->left_child[i]);
            }
            if(root->type==1){
                cout<<root->data<<" ";
            }
            else{
                cout<<"Decision ";
            }
            inorder(root->left_child[root->left_child.size()-1]);
        }
        else{
            cout<<root->data<<" ";
        }
    }
    void create_decision_tree(vector<int> arr,node** d1, node** d2){
        if((*d1)->decision=="greater" && (*d2)->decision=="less"){
            for(int i=0;i<arr.size();i++){
                if((*d1)->parameter<arr[i]){
                    node* temp = new node(arr[i]);
                    ((*d1)->child).push_back(temp);
                }
            }
            ((*d1)->child).push_back(*d2);
            for(int i=0;i<arr.size();i++){
                if((*d2)->parameter>arr[i]){
                    node* temp = new node(arr[i]);
                    ((*d2)->child).push_back(temp);
                }
            }
    }
};
int main(){
    decision_tree d;
    node* d1 = new node("greater");
    d1->decision="greater";
    d1->parameter=7;
    node* d2 = new node("less");
    d2->parameter=4;
    d2->decision="less";
    vector<int>arr{1,2,4,5,6,7,8,9};
    d.create_decision_tree(arr,&d1,&d2);
    // d.inorder(d1);
    return 0;
}