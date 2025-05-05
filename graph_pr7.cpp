// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct Node {
    Node *next;
    char data;

    Node(char val) {
        data = val;
        next = nullptr;
    }
};

class Graph {
    public:
        int n;
        vector<Node*> list;
        vector<vector<int>> mat;
        vector<char> vertices;

        Graph() {
            cout<<"Enter total number of vertices:";
            cin>>n;
            mat.resize(n,vector<int>(n,0));
        }

        void accept() {
            char x, check;

            for(int i = 0; i < n; i++) {
                cout<<"Enter name of vertex "<<i + 1<< " : ";
                cin>>x;

                vertices.push_back(x);
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout<<"Is there edge between "<<vertices[i]<<" and "<<vertices[j]<<" ? [y/n]:";
                    cin>>check;

                    if(check == 'y' || check == 'Y') {
                        mat[i][j] = 1;
                    } else {
                        mat[i][j] = 0;
                    }
                }
            }
        }

        void display_mat() {
            cout<<endl;
            cout<<"=====Adjacency Matrix====="<<endl;
            for(int i = 0; i < n; i++) {
                cout<<"\t"<<vertices[i];
            }
            cout<<endl;
            for(int i = 0; i < n; i++) {
                cout<<vertices[i];
                for(int j = 0; j < n; j++) {
                    cout<<"\t"<<mat[i][j];
                }
                cout<<endl;
            }
        }

        void display_list() {
            cout<<endl;
            for(int i = 0; i < n; i++) {
                list.push_back(new Node(vertices[i]));
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] == 1) {
                        Node *temp = list[i];
                        while(temp->next != nullptr) {
                            temp = temp->next;
                        }
                        temp->next = new Node(vertices[j]);
                    }
                }
            }

            cout<<"=====Adjacency List====="<<endl;
            for(int i = 0; i < n; i++) {
                cout<<list[i]->data;
                Node *temp = list[i]->next;

                while(temp != nullptr) {
                    cout<<"->"<<temp->data;
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        void BFS(char start) {
            cout<<endl;
            cout<<"BFS traversal:";
            int start_index = 0;
            for(int i = 0; i < n; i++) {
                if(start == vertices[i]) {
                    start_index = i;
                }
            }

            queue<int> q;
            vector<bool> visited(n, false);
            q.push(start_index);
            visited[start_index] = true;

            while(!q.empty()) {
                int index = q.front();
                q.pop();
                cout<<vertices[index]<<" ";

                for(int i = 0; i < n; i++) {
                    if(mat[index][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        void DFS(char start) {
            cout<<endl;
            cout<<"DFS traversal:";
            int start_index = 0;

            for(int i = 0; i < n; i++) {
                if(start == vertices[i]) {
                    start_index = i;
                }
            }

            stack<int> s;
            vector<bool> visited(n, false);
            s.push(start_index);
            visited[start_index] = true;
            cout<<vertices[start_index]<<" ";

            while(!s.empty()) {
                int index = s.top();
                bool neighbour = false;

                for(int i = 0; i < n; i++) {
                    if(mat[index][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        s.push(i);
                        neighbour = true;
                        cout<<vertices[i]<<" ";
                        break;
                    }
                }

                if(neighbour == false) {
                    s.pop();
                }
            }
        }
};

int main() {
    Graph g;

    g.accept();
    g.display_mat();
    g.display_list();
    g.BFS('A');
    g.DFS('A');

    return 0;
}