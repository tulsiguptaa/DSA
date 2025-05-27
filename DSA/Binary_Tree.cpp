#include <bits/stdc++.h>
using namespace std;


// ---------creating node using struct 
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// -----------creating node also using class
class TreeNode {
    public:
        int data;      
        TreeNode* left;  
        TreeNode* right;   
        TreeNode(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

// -----------DFS (Depth first search)-----------

// -----------preorder traversal
void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// ----------preorder traversal using iteration
void preorder_(Node* root){
    if(root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* current = st.top();
        st.pop();
        cout<<current->data<<" ";
        if(current->right){
            st.push(current->right);
        }
        if(current->left){
            st.push(current->left);
        }
    }
}

// ----------inorder traversal
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// ----------inorder traversal using iteration
void inorder_(Node* root){
    if(root == nullptr) return;
    stack<Node*> st;
    Node* current = root;
    while(!st.empty() || current != nullptr){
        while(current!= nullptr){
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout<<current->data<<" ";
        current = current->right;
    }
}

// ----------postorder traversal
void postorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

// -----------postorder yraversal using iteration using 2 stack
void postorder_(Node* root){
    if(root == nullptr) return;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* current = st1.top();
        st1.pop();
        st2.push(current);
        if(current->left){
            st1.push(current->left);
        }
        if(current->right){
            st1.push(current->right);
        }
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

// --------------post order traversal using one stack iteration
void postorder__(Node* root){
    if(root == nullptr) return;
    stack<Node*> st;
    Node* current = root;
    Node* lastVisitedNode = nullptr;
    while(current!=nullptr || !st.empty()){
        if (current != nullptr) {
            st.push(current);
            current = current->left;
        } else {
            Node* peekNode = st.top();

            // If right child exists and traversing node from left child, then move right
            if (peekNode->right != nullptr && lastVisitedNode != peekNode->right) {
                current = peekNode->right;
            } else {
                cout << peekNode->data << " ";
                lastVisitedNode = peekNode;
                st.pop();
            }
        }
    }
}

// -----------BFS(Breadth first search)-------------
// ---------level order traversal
void levelorder(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
}





int main() {
    // ------------struct
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // ----------class
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);

    // ---------preorder traversal
    // cout<<"Preorder Traversal: ";
    // preorder(root);


    // ---------preorder traversal using iteration
    // cout<<"Iterative Preorder Traversal: ";
    // preorder_(root);


    // -----------inorder traversal
    // cout<<"Inorder Traversal: ";
    // inorder(root);


    // -----------inorder traversal using iteration
    // cout<<"Iterative Inorder Traversal: ";
    // inorder_(root);


    // -----------postorder traversal
    // cout<<"Postorder Traversal: ";
    // postorder(root);


    // -----------postorder traversal using 2 stack iteration
    // cout<<"Iterative Postorder Traversal: ";
    // postorder_(root);


    // -----------postorder traversal using 1 stack iteration
    cout<<"Iterative Postorder Traversal: ";
    postorder__(root);


    // -----------level order traversal
    // cout << "Level Order Traversal: ";
    // levelorder(root);
    return 0;
}