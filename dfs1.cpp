#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

class Graph {

    private:

        int nodes;
        list<int> *adjlist;
        vector<bool> visited;

    public:


        Graph (int nodes) {
            adjlist = new list<int> [nodes];
            visited.resize(nodes, false);
            this->nodes = nodes;
        }

        ~Graph () {
        }

    void AddEdge (int src, int dst) {
            adjlist[src].push_back(dst);
            adjlist[dst].push_back(src);
        }

        void DFS (int src) {
            visited[src] = true;
            cout << src << " ";
            for (auto& adj_node : adjlist[src]) {
                if (!visited[adj_node]) {
                    DFS(adj_node);
                }
            }
        }

       void DFS_Iterative (int src) {

           stack<int> stk;
           visited[src] = true;
           stk.push(src);

           while (!stk.empty()) {
               src = stk.top();
               stk.pop();
               cout << src << " ";
               for (auto &adj_node : adjlist[src]) {
                   if (!visited[adj_node]) {
                       visited[adj_node] = true;
                       stk.push(adj_node);
                   }
               }
           }
       }
};
int main()
{

    Graph g(9);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,3);
    g.AddEdge(1,4);
    g.AddEdge(2,3);
    g.AddEdge(3,5);
    g.AddEdge(4,6);
    g.AddEdge(5,6);
    cout << "Depth First Traversal(starting from vertex 2)"<<endl;

    g.DFS(4);

return 0;
}
