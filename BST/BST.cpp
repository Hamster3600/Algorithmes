#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->value) {
        root->left = insert(root->left, val);
    } else if (val > root->value) {
        root->right = insert(root->right, val);
    }
    return root; 
}

bool search(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->value == val) return true;
    if (val < root->value)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->value << " ";
    inorder(root->right);
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* removeNode(Node* root, int val) {
    if (root == nullptr) return root;

    if (val < root->value) {
        root->left = removeNode(root->left, val);
    } else if (val > root->value) {
        root->right = removeNode(root->right, val);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Inorder: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Is 40 in BST? " << (search(root, 40) ? "Tak" : "Nie") << "\n";

    root = removeNode(root, 50);

    std::cout << "Inorder after removing 50: ";
    inorder(root);
    std::cout << "\n";

    return 0;
}
