#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    int level;
    vector<node*> child;
    node(int data,int level){
        this->data = data;
        this->level = level;
        if(level%2==0){
            child.resize(4);
        }
        else{
            child.resize(2);
        }
        for(int i=0;i<child.size();i++){
            child[i] = nullptr;
        }
    }
};

class Tree{
    public:
    node* root = nullptr;
    Tree(node* root){
        this->root=root;
    }
    node* create_node(int data, int level){
        node *temp = new node(data,level);
        return temp;
    }
    node* create_tree(int size){
        queue<node*> Q;
        int data = 1;
        root = new node(data,1);
        Q.push(root);
        node* temp;
        while(true){
            temp = Q.front();
            Q.pop();
            for(int i=0;i<temp->child.size();i++){
                temp->child[i] = create_node(++data,temp->level+1);
                if(temp->child[i]->data == size){
                    break;
                }
                Q.push(temp->child[i]);
            }
            if(data==size){
                break;
            }
        }
        return root;
    }

    void levelorder(){
        queue<node*> Q;
        Q.push(root);
        node* temp;
        bool isLastNode = false;
        int level=1;
        cout<<"L"<<level<<"--";
        cout<<root->data;
        while(!isLastNode){
            temp = Q.front();
            Q.pop();
            for(int i=0;i<temp->child.size();i++){
                if(temp->child[i]==nullptr){
                    isLastNode=true;
                    break;
                }
                if(level<temp->child[i]->level){
                    level++;
                    cout<<endl;
                    cout<<"L"<<level<<"--";
                }
                cout<<temp->child[i]->data<<" ";
                Q.push(temp->child[i]);
            }
            if(isLastNode){break;}
        }
        cout<<endl;
    }

    int path_sum(node* root, int data, int sum){
        if(root==nullptr){
            return 0;
        }
        else if(root->data==data){
            return sum+root->data;
        }
        int a=0;
        for(int i=0;i<root->child.size();i++){
            a = a|path_sum(root->child[i],data,sum+root->data);
            if(a!=0){
                break;
            }
        }
        return a;
    }
};

int main(){
    node* root = nullptr;
    Tree t = Tree(root);
    int N;
    cout<<"Enter the value of N\n";
    cin>> N;
    t.create_tree(N);
    cout<<"The LEVEL ORDER traversal for the tree is\n";
    t.levelorder();
    cout<<"\nThe path cost is equal to ";
    int ans = t.path_sum(t.root,N,0);
    cout<<ans<<endl;
    return 0;
}
