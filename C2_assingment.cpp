#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{
	int V; 
	list<int> *adj;
public:
    Graph(int V) 
    { 
        this->V = V;
        this->adj = new list<int>[V];
    }  
    void DFS(int v, vector<bool> &visited) 
    { 
        visited[v] = true; 
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFS(*i, visited); 
    }
    void add_edge(int v, int w) 
    { 
        adj[v].push_back(w);
    } 
    int find_vertex() 
    { 
        vector<bool>visited(V, false);
        int v = 0; 
        for (int i=0;i<V; i++){ 
            if (visited[i] == false){ 
                DFS(i, visited); 
                v = i; 
            }
        } 
        fill(visited.begin(), visited.end(), false); 
        DFS(v, visited); 
        for (int i=0; i<V; i++){
            if (visited[i] == false){return -1;}
        }

        return v; 
    } 
};
int main() 
{
    int n;
    cout<<"Enter the number of nodes in the graph"<<endl;
    cin>>n;
	Graph g(n);
    int p,q;
    int s=0;

    // Enter vertices as space seperated input.
    // Enter -1 to exit.
    while(true){
        cout<<"Enter vertex "<<++s<<endl;
        cin>>p;
        if(p==-1){
            break;
        }
        cin>>q;
        g.add_edge(p,q);
    }

    //SAMPLE INPUT

    // Enter the number of nodes in the graph
    // 5
    // Enter vertex 1
    // 0 1
    // Enter vertex 2
    // 0 2
    // Enter vertex 3               >1<-------- 0
    // 2 3                        /  |       /  | 
    // Enter vertex 4           /    |    /     | 
    // 1 3                    /      V L        V
    // Enter vertex 5       4<------ 3 <------- 2       
    // 3 0
    // Enter vertex 6
    // 4 1
    // Enter vertex 7
    // 3 4
    // Enter vertex 8
    // -1

    //OUTPUT
    //The vertex containing path to every other vertex is 0

    int ans = g.find_vertex();
    if(ans==-1){
        cout<<"Sorry but no such vertex exists."<<endl;
    }
    else{
        cout<<"The vertex containing path to every other vertex is Vertex " <<ans<<endl;
    }
	return 0; 
} 
