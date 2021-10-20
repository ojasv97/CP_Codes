#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildTree(vector<int> arr){
    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);
    int i = 0;
    while(i<arr.size() && !q.empty()){
        node* x = q.front();
        q.pop();
        if(i+1<arr.size()){
            i++;
            node* y = new node(arr[i]);
            x->left = y;
            q.push(y);
        }
        if(i+1<arr.size()){
            i++;
            node* y = new node(arr[i]);
            x->right = y;
            q.push(y);
        }
    }
    return root;
}

void inorder(node* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preOrder(node* root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* p = st.top();
        cout<<p->data<<" ";
        st.pop();
        if(p->right){
            st.push(p->right);
        }
        if(p->left){
            st.push(p->left);
        }
    }
}

void inOrder(node* root){
    stack<node*> st;
    while(root != nullptr || !st.empty()){
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
}

void postOrder(node* root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* p = st.top();
        st.pop();
        if(p->left){
            st.push(p->left);
        }
        if(p->right){
            st.push(p->right);
        }
        cout<<p->data<<" ";
    }

}
int main(){
    vector<int> a{1,2,3,4,5,6,7,8,9};
    node* root = buildTree(a);
    postOrder(root);
    return 0;
}