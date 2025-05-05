// A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.

#include<iostream>
#include<string.h>
using namespace std;

struct Node {
    Node *child[10];
    string label;
    int count;
};

class Book {
    Node *root;
    public:
        Book() {
            root = nullptr;
        }
       
        void createTree() {
            root = new Node;
            cout<<"Enter name of the book: ";
            cin>>root->label;
            cout<<"Enter number of chapters in the book "<<root->label<<" : ";
            cin>>root->count;
           
            for(int i = 0; i < root->count; i++) {
                root->child[i] = new Node;
                cout<<"Enter chapter name for chapter number "<<i+1<<" : ";
                cin>>root->child[i]->label;
                cout<<"Enter number of sections in "<<root->child[i]->label<<" : ";
                cin>>root->child[i]->count;
               
                for(int j = 0; j < root->child[i]->count; j++) {
                    root->child[i]->child[j] = new Node;
                    cout<<"Enter section name for section number "<<j+1<<" : ";
                    cin>>root->child[i]->child[j]->label;
                    cout<<"Enter number of sub sections in "<<root->child[i]->child[j]->label<<" : ";
                    cin>>root->child[i]->child[j]->count;
                   
                    for(int k = 0; k < root->child[i]->child[j]->count; k++) {
                        root->child[i]->child[j]->child[k] = new Node;
                        cout<<"Enter sub section name for sub section number "<<k+1<<" : ";
                        cin>>root->child[i]->child[j]->child[k]->label;
                    }
                }
            }
        }
       
        void displayTree() {
            if(root == nullptr) {
                cout<<"Book structure not available"<<endl;
                return;
            }
           
            cout<<"Book Name:"<<root->label<<endl;
            for(int i = 0; i < root->count; i++) {
                cout<<"Chapter Name:"<<root->child[i]->label<<endl;
                for(int j = 0; j < root->child[i]->count; j++) {
                    cout<<"\t Section Name:"<<root->child[i]->child[j]->label<<endl;
                    for(int k = 0; k < root->child[i]->child[j]->count; k++) {
                        cout<<"\t \t Sub Section Name:"<<root->child[i]->child[j]->child[k]->label<<endl;
                    }
                }
            }
        }
};

int main() {
    Book b;
    cout<<"Book Structure"<<endl;
    b.createTree();
    cout<<endl;
    cout<<"===BOOK STRUCTURE==="<<endl;
    b.displayTree();
    return 0;
}
