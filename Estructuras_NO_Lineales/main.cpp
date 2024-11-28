#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;       
    int value;     
    int height;    
    Node* left;    
    Node* right;   

    Node(int k, int v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};


int getHeight(Node* node) {
    return node ? node->height : 0;
}

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;


    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key, 1);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        node->value++;
        return node;
    }

    updateHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

int calculateCost(Node* node, int c) {
    if (!node) return 0;

    int cost = min(node->value, c);
    cost += calculateCost(node->left, c);
    cost += calculateCost(node->right, c); 

    return cost;
}

void deleteTree(Node* node) {
    if (!node) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        Node* root = nullptr; 

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            root = insert(root, a);
        }

        int totalCost = calculateCost(root, c);

        cout << totalCost << endl;

        deleteTree(root);
    }

    return 0;
}
