#include <bits/stdc++.h>
using namespace std;

// --------Binary tree implementation using struct
struct node1{
    int data;
    node1* left = nullptr;
    node1* right = nullptr;
};

// --------Binary tree implementation using class
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
 
// -----------build tree using preorder sequence
static int idx = -1;
node* buildPreorder(vector<int> preorderArray){
    idx ++;
    if(preorderArray[idx] == -1) return nullptr; 
    node* root = new node(preorderArray[idx]);
    root->left = buildPreorder(preorderArray);
    root->right = buildPreorder(preorderArray);
    return root; 
}

// --------------preorder traversal
void preorder(node* root){
    if(root == nullptr)return ;
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);
}

// -------------inorder traversal
void inorder(node* root){
    if(root == nullptr)return;
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}

// -------------postorder traversal
void postorder(node* root){
    if(root == nullptr) return;
    postorder(root->left); 
    postorder(root->right);
    cout<<root->data<<"->"; 
}

// ----------level order traversal
void levelorder(node* root){
    queue<node*> st;
    if(root == nullptr) return;
    st.push(root); 
    while(st.size()>0){
        node* curr = st.front();
        st.pop();
        cout<<curr->data<<"->";
        if(curr->left != nullptr){
            st.push(curr->left);
        }
        if(curr->right != nullptr){
            st.push(curr->right);
        }
    }
    cout<<endl;
}

// ------------level order traversal with different levels in different lines
void levelorder_(node* root){
    if(root == nullptr) return;
    queue<node*> st;
    st.push(root);
    st.push(nullptr);
    while(st.size()>0){
        node* curr = st.front();
        st.pop();
        if(curr == nullptr){
           if(!st.empty()){
            cout<<endl;
            st.push(nullptr);
            continue;
           }
           else{
            break;
           }
        }
        cout<<curr->data<<"->";
        if(curr->left != nullptr){
            st.push(curr->left);
        }
        if(curr->right != nullptr){
            st.push(curr->right);
        }
    }
}

// -----------height of the tree
void height(node* root){
    if(root == nullptr) return;
    queue<node*> st;
    st.push(root);
    int ht = 1;  
    st.push(nullptr);
    while(st.size()>0){
        node* curr = st.front();
        st.pop();
        if(curr == nullptr){
            if(!st.empty()){
                ht++;
                st.push(nullptr);
                continue;
            }
            else{
                break;
            }
        }
        if(curr->left != nullptr){
            st.push(curr->left);
        }
        if(curr->right != nullptr){
            st.push(curr->right);
        }
    }
    cout<<ht;
}

// ------------height of the tree using recursion
int height_(node* root){
    if(root == nullptr) return 0;
    int leftht = height_(root->left);
    int rightht = height_(root->right);
    return max(leftht, rightht) + 1;
}

// ----------count the total nodes
int totalNodes(node* root){
    if(root == nullptr) return 0;
    int leftNodes = totalNodes(root->left);
    int rightNodes = totalNodes(root->right);
    return (leftNodes + rightNodes) + 1;
}

// -----------sum of all the nodes
int sumNodes(node* root){
    if(root == nullptr) return 0;
    int leftNodes = sumNodes(root->left);
    int rightNodes = sumNodes(root->right);
    return leftNodes + rightNodes + root->data;
}

// ------------check two tree are identical or not
bool identical(node* root1, node* root2){
    if(root1 == nullptr || root2 == nullptr) return root1 == root2;
    bool leftSubtree = identical(root1->left, root2->left);
    bool rightSubtree = identical(root1->right,  root2->right);
    return leftSubtree && rightSubtree && root1->data == root2->data;   
}

// --------------check subtree of another tree
bool checkSubtree(node* root, node* subroot){
    if(root == nullptr || subroot == nullptr){
        return root == subroot;
    }
    if(root->data == subroot->data && identical(root,subroot)){
        return true;
    }   
    return checkSubtree(root->left, subroot) || checkSubtree(root->right, subroot);
}

// ---------------diameter of a tree
int diameter(node* root){
    if(root == nullptr) return 0;
    int leftleaf = diameter(root->left);
    int rightleaf = diameter(root->right);
    int curr = height_(root->left) + height_(root->right);
    return max(curr, max(leftleaf, rightleaf));
}

// --------------diameter of the tree using optimisation
int ans = 0;
int height__(node* root){
    if(root == nullptr) return 0;
    int leftht = height__(root->left);
    int rightht = height__(root->right);
    ans = max(ans, leftht + rightht) + 1;
    return max(leftht, rightht) + 1;
}
int diameter_(node* root) {
    height__(root);
    return ans;
}


int main() {
    vector<int> preorderArray = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    node* root = buildPreorder(preorderArray); 

    node* root1 = new node(3);
    root1->left = new node(4);
    root1->right = new node(5);
 
    // preorder(root);

    // inorder(root);

    // postorder(root);

    // levelorder(root);

    // levelorder_(root);

    // height(root);

    // cout<<"The height of the tree is: "<<height_(root);

    // cout<<"The total nodes in a trees is: "<<totalNodes(root);

    // cout<<"The sum of all the nodes are: "<<sumNodes(root);

    // cout<<"Both are: "<<identical(root, root);

    // cout<<"The main tree have a subtree: "<<checkSubtree(root,root1);

    // cout<<"The diameter of the tree is: "<<diameter(root);

    cout<<"The diameter of the tree is: "<<diameter_(root);


    
    return 0;
}