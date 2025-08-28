#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int value;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

void rotateLeft(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotateRight(Node*& root, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void fixInsert(Node*& root, Node* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

Node* insert(Node* root, int val) {
    Node* z = new Node;
    z->value = val;
    z->color = RED;
    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr;

    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (val < x->value) x = x->left;
        else if (val > x->value) x = x->right;
        else { 
            delete z;
            return root;
        }
    }

    z->parent = y;
    if (y == nullptr) root = z;
    else if (val < y->value) y->left = z;
    else y->right = z;

    fixInsert(root, z);
    return root;
}

bool search(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->value == val) return true;
    if (val < root->value) return search(root->left, val);
    else return search(root->right, val);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->value << (root->color == RED ? "(R) " : "(B) ");
    inorder(root->right);
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

void fixDelete(Node*& root, Node* x) {
    while (x != root && (x == nullptr || x->color == BLACK)) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == BLACK) {
                    if(w->left) w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if(w->right) w->right->color = BLACK;
                rotateLeft(root, x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == BLACK) {
                    if(w->right) w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if(w->left) w->left->color = BLACK;
                rotateRight(root, x->parent);
                x = root;
            }
        }
    }
    if(x) x->color = BLACK;
}

Node* removeNode(Node*& root, int val) {
    Node* z = root;
    while (z != nullptr) {
        if (val == z->value) break;
        else if (val < z->value) z = z->left;
        else z = z->right;
    }
    if (z == nullptr) return root;

    Node* y = z;
    Color yOriginalColor = y->color;
    Node* x = nullptr;

    if (z->left == nullptr) {
        x = z->right;
        if(x) x->parent = z->parent;
        if (z->parent == nullptr) root = x;
        else if (z == z->parent->left) z->parent->left = x;
        else z->parent->right = x;
    } else if (z->right == nullptr) {
        x = z->left;
        if(x) x->parent = z->parent;
        if (z->parent == nullptr) root = x;
        else if (z == z->parent->left) z->parent->left = x;
        else z->parent->right = x;
    } else {
        Node* minRight = z->right;
        while (minRight->left) minRight = minRight->left;
        y = minRight;
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            if(x) x->parent = y;
        } else {
            if(y->parent) {
                if(y->parent->left == y) y->parent->left = x;
                else y->parent->right = x;
            }
            if(x) x->parent = y->parent;
            y->right = z->right;
            if(y->right) y->right->parent = y;
        }
        if(z->parent == nullptr) root = y;
        else if(z == z->parent->left) z->parent->left = y;
        else z->parent->right = y;
        y->parent = z->parent;
        y->left = z->left;
        if(y->left) y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (yOriginalColor == BLACK && root != nullptr) fixDelete(root, x);
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

    std::cout << "Inorder (with colors): ";
    inorder(root);
    std::cout << "\n";

    std::cout << "is 40 in the tree? " << (search(root, 40) ? "Yes" : "No") << "\n";

    root = removeNode(root, 50);
    std::cout << "Inorder after deleting 50: ";
    inorder(root);
    std::cout << "\n";

    return 0;
}
