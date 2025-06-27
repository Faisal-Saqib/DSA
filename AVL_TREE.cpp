struct Node {
    int key;
    int height;  // Height of the node
    int size;    // Size of the subtree rooted at this node
    int count;   // Frequency of the key
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), size(1), count(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    Node* root;

    // Utility functions
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getSize(Node* node) {
        return node ? node->size : 0;
    }

    void updateNode(Node* node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            node->size = getSize(node->left) + getSize(node->right) + node->count;
        }
    }

    // Right rotate
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateNode(y);
        updateNode(x);

        return x;
    }

    // Left rotate
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateNode(x);
        updateNode(y);

        return y;
    }

    // Get balance factor
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Insert key into AVL tree
    Node* insert(Node* node, int& key) {
        if (!node) return new Node(key);

        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);
        else {
            node->count++;
            updateNode(node);
            return node;
        }

        updateNode(node);

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) return rotateRight(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key) return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Remove key from AVL tree
    Node* remove(Node* node, int& key) {
        if (!node) return node;

        if (key < node->key) node->left = remove(node->left, key);
        else if (key > node->key) node->right = remove(node->right, key);
        else {
            if (node->count > 1) {
                node->count--;
                updateNode(node);
                return node;
            }

            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->count = temp->count;
            temp->count = 1;
            node->right = remove(node->right, temp->key);
        }

        updateNode(node);

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) return rotateRight(node);

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) return rotateLeft(node);

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Find minimum value node
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // Count elements < key
    int countLess(Node* node, int& key) {
        if (!node) return 0;

        if (key <= node->key) {
            return countLess(node->left, key);
        }

        return getSize(node->left) + node->count + countLess(node->right, key);
    }

public:
    AVLTree() : root(nullptr) {}

    void add(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    int countLess(int key) {
        return countLess(root, key);
    }
};