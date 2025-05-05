// Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree - i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data value found in the tree, iv. Change a tree so that the roles of the left and right pointers are swapped at every node, v. Search a value

#include<iostream>
using namespace std;

struct Node {
    Node *right, *left;
    int data;

    Node(int val) {
        right = nullptr;
        left = nullptr;
        data = val;
    }
};

class BST {
    Node *root;

    public:
        BST() {
            root = nullptr;
        }

        void create(int data) {
            if (root == nullptr) {
                root = new Node(data);
                cout << "BST created with root " << data << endl;
            } else {
                cout << "BST already created" << endl;
            }
        }

        void insert(int data) {
            root = insert(root, data);
        }

        void displayInOrder() {
            cout << "In-order Traversal: ";
            displayIn(root);
            cout << endl;
        }

        void displayPreOrder() {
            cout << "Pre-order Traversal: ";
            displayPre(root);
            cout << endl;
        }

        void displayPostOrder() {
            cout << "Post-order Traversal: ";
            displayPost(root);
            cout << endl;
        }

        // i. Insert 
        Node *insert(Node *root, int data) {
            if (root == nullptr) {
                return new Node(data);
            } else if (data <= root->data) {
                root->left = insert(root->left, data);
            } else {
                root->right = insert(root->right, data);
            }
            return root;
        }

        void displayIn(Node *root) {
            if (root != nullptr) {
                displayIn(root->left);
                cout << root->data << " ";
                displayIn(root->right);
            }
        }

        void displayPost(Node *root) {
            if (root != nullptr) {
                displayPost(root->left);
                displayPost(root->right);
                cout << root->data << " ";
            }
        }

        void displayPre(Node *root) {
            if (root != nullptr) {
                cout << root->data << " ";
                displayPre(root->left);
                displayPre(root->right);
            }
        }

        // ii. Find number of nodes in longest path from root (height)
        int findLongestPath() {
            return height(root);
        }

        int height(Node *node) {
            if (node == nullptr)
                return 0;
            int l = height(node->left);
            int r = height(node->right);
            return max(l, r) + 1;
        }

        // iii. Find minimum data value
        int findMin() {
            if (root == nullptr) {
                cout << "Tree is empty!" << endl;
                return -1;
            }
            Node *curr = root;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            return curr->data;
        }

        // iv. Mirror the tree
        void mirrorTree() {
            mirror(root);
        }

        void mirror(Node *node) {
            if (node == nullptr)
                return;
            swap(node->left, node->right);
            mirror(node->left);
            mirror(node->right);
        }

        // v. Search a value
        bool search(int key) {
            return search(root, key);
        }

        bool search(Node *node, int key) {
            if (node == nullptr)
                return false;
            if (node->data == key)
                return true;
            else if (key < node->data)
                return search(node->left, key);
            else
                return search(node->right, key);
        }
};

int main() {
    BST b;
    b.create(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);

    cout << "\n--- Tree Traversals ---\n";
    b.displayInOrder();
    b.displayPreOrder();
    b.displayPostOrder();

    cout << "\n--- Insert New Node 12 ---\n";
    b.insert(12);
    b.displayInOrder();

    cout << "\n--- Height of the Tree ---\n";
    cout << "Longest path from root: " << b.findLongestPath() << " nodes\n";

    cout << "\n--- Minimum Data Value ---\n";
    cout << "Minimum value: " << b.findMin() << endl;

    cout << "\n--- Mirror Tree ---\n";
    b.mirrorTree();
    b.displayInOrder();  // To see the mirrored tree

    cout << "\n--- Search for 15 ---\n";
    cout << (b.search(15) ? "Found!" : "Not Found") << endl;

    cout << "\n--- Search for 100 ---\n";
    cout << (b.search(100) ? "Found!" : "Not Found") << endl;

    return 0;
}
