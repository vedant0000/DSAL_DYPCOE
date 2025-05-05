// Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order traversal (non recursive) and then delete the entire tree.

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;

    Node(char val) {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};

class Exp {
    public:
        Node *root;

        // Check variable
        bool isExp(char c) {
            return (c == '+' || c == '-' || c == '*' || c == '/');
        }

        // Construct Tree
        Node *constructTree(string prefix) {
            stack<Node*> st;

            for(int i = prefix.length() - 1; i >= 0; i--) {
                char c = prefix[i];
                Node *node = new Node(c);

                if(isExp(c)) {
                    Node *left = st.top(); st.pop();
                    Node *right = st.top(); st.pop();
                    node->left = left;
                    node->right = right;
                }
                st.push(node);
            }

            if(!st.empty()) {
                root = st.top();
            }

            return root;
        }

        // Post order traversal
        void postOrder() {
            if(root == nullptr) {
                return;
            }

            stack<Node*> s1, s2;
            s1.push(root);

            while(!s1.empty()) {
                Node *curr = s1.top(); s1.pop();
                s2.push(curr);

                if(curr->left) {
                    s1.push(curr->left);
                }

                if(curr->right) {
                    s1.push(curr->right);
                }
            }

            cout<<"Post Order:";
            while(!s2.empty()) {
                cout<<s2.top()->data;
                s2.pop();
            }
            cout<<endl;
        }

        // Delete Tree
        void deleteTree() {
            if(root == nullptr) {
                return;
            }

            stack<Node*> st;
            st.push(root);

            while(!st.empty()) {
                Node *curr = st.top(); st.pop();

                if(curr->left) {
                    st.push(curr->left);
                }

                if(curr->right) {
                    st.push(curr->right);
                }

                delete curr;
            }

            root = nullptr;
            cout<<"Deleted";
        }
};

int main() {
    Exp e;
    string prefix = "+--a*bc/def";

    e.constructTree(prefix);
    e.postOrder();
    e.deleteTree();
    return 0;
}
