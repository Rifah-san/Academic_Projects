#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Creating a binary tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    
    cout << "Height of tree: " << height(root) << endl;
    cout << "Total nodes: " << countNodes(root) << endl;
    
    return 0;
}
