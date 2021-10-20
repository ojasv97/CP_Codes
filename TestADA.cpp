// A recursive C++ program to print  
// REVERSE level order traversal  
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data,  
pointer to left and right child */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
/*Function protoypes*/
void printGivenLevel(node* root, int level);  
int height(node* node);  
node* newNode(int data);
  
/* Function to print REVERSE  
level order traversal a tree*/
void reverseLevelOrder(node* root)  
{  
    int h = height(root);  
    int i;  
    for (i=h; i>=1; i--)
        printGivenLevel(root, i);
}  
  
/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{  
    if (root == NULL)  
        return;
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }  
}  
  
/* Compute the "height" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of left and right subtree */
        int lh = height(node->left);  
        int rh = height(node->right);  
        /* use the larger one */
        return lh > rh ? lh+1 : rh+1;
    }  
}  
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    return(Node);  
}  
  
/* Driver code*/
int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->right->right = newNode(4);  
    root->right->right->right = newNode(6);  
    root->right->right->left = newNode(5);
  
    cout << "Level Order traversal of binary tree is \n";  
    reverseLevelOrder(root);  
  
    return 0;  
  
}  