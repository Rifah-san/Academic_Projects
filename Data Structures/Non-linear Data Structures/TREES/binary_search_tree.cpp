#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* createNode(int value) {
    BSTNode* newNode = new BSTNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BSTNode* insert(BSTNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

bool search(BSTNode* root, int value) {
    if (root == nullptr) return false;
    
    if (root->data == value) return true;
    else if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

BSTNode* deleteNode(BSTNode* root, int value) {
    if (root == nullptr) return root;
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node with two children
        BSTNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(BSTNode* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    BSTNode* root = nullptr;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not found") << endl;
    
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;
    
    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;
    
    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
