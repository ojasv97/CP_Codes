#include<bits/stdc++.h>
using namespace std;
class gen_tree{
    public:
    int data;
    vector<gen_tree*> child;
    gen_tree(int data,int n){
        this->data=data;
    }
    void inorder_gentree(gen_tree *root){
        if(root->child.size()!=0){
            for(int i=0;i<root->child.size()-1;i++){
                inorder_gentree(root->child[i]);
            }
            cout<<root->data<<" ";
            inorder_gentree(root->child[root->child.size()-1]);
        }
        else{
            cout<<root->data<<" ";
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
        cout<<root->data<<" ";
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
class graph{
    public:
    vector<vector<int>> adj;
    unordered_map<int,gen_tree*> add;
    int edges;
    int vertices;
    void addVertices(int n){
        this->vertices=n;
        for(int i=0;i<n;i++){
            vector<int> temp;
            adj.push_back(temp);
        }
    }
    void createEdge(int a, int b){
        adj[a].push_back(b);
    }
    void addEdge(){
        int n=4;
        printf("The number of edges is %d\n",4);
        this->edges=n;
        int a,b;
        //This is our graph.
        printf("Enter the edges\n");
        createEdge(0,1);
        createEdge(1,2);
        createEdge(1,3);
        createEdge(2,3);
    }
    vector<vector<gen_tree*>> BFS(){
        queue<int> q;
        vector<vector<gen_tree*>> tree;
        bool visited[vertices];
        for(int i=0;i<vertices;i++){
            vector<gen_tree*> ch;
            tree.push_back(ch);
            visited[i]=false;
        }
        q.push(0);
        visited[0]=true;
        while (!q.empty())
        { 
            int s = q.front();
            gen_tree* temp = new gen_tree(s,adj[s].size());
            (this->add).insert({s,temp});
            q.pop();
            int i=0;
            for (auto u : adj[s]) {
                if (visited[u]){continue;}
                gen_tree* a = new gen_tree(u,adj[u].size());
                tree[s].push_back(a);
                i++;
                visited[u] = true;
                q.push(u);
            }
        }
        return tree;
    }
    gen_tree** make_tree(vector<vector<gen_tree*>> tree){
        queue<gen_tree**> q;
        gen_tree* p = new gen_tree(add[0]->data,tree[0].size());
        gen_tree** root = &p;
        unordered_map<int,gen_tree*> address;
        q.push(root);
        while(!q.empty()){
            gen_tree* temp = *(q.front());
            if(temp->data>tree.size()-1){
                q.pop();
                continue;
            }
            q.pop();
            for(int i=0;i<tree[temp->data].size();i++){
                if(address.find((tree[temp->data][i])->data)==address.end()){
                    gen_tree* node = new gen_tree((tree[temp->data][i])->data,tree[i].size());
                    temp->child.push_back(node);
                    address.insert({(tree[temp->data][i])->data,node});
                }
                else{
                    temp->child.push_back(address[(tree[temp->data][i])->data]);
                }
                q.push(&(temp->child[i]));
            }
        }
        return root;
    } 
};
int main(){
    graph g;
    g.addVertices(4);
    g.addEdge();
    //        0------1                                   0
    //              /|                                   |
    //            /  | -------------------------->       |
    //          /    |                                   1-----2  
    //        2------3                                  /
    //                                                 /
    //                                                3
    gen_tree* root = nullptr;
    vector<vector<gen_tree*>> tree;
    tree = g.BFS();
    root = *(g.make_tree(tree)); 
    root->inorder_bintree(root);
    return 0;
}