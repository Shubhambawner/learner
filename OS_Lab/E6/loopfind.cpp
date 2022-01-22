#include <iostream>
#include <list>

using namespace std;

// C++ implementation of Graph using Adjesency list
class Graph
{
    public:
    int V;                                              // No. of vertices
    list<int> *adj;                                     // Pointer to an array containing adjacency lists
     

    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) // to add an edge to graph
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

    // This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
    bool isCyclicUtil(int v, bool visited[], bool *recStack)
    {
        if (visited[v] == false)
        {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
    }

    // Returns true if the graph contains a cycle, else false.
    bool isCyclic() // returns true if there is a cycle in this graph
    {
        // Mark all the vertices as not visited and not part of recursion
        // stack
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;

        return false;
    }
};

int main()
{
    // Create a graph given in the above diagram

    cout << "Enter the total number of resources --";
    int r;
    cin >> r;
    cout << "Enter the total number of processes --";
    int p;
    cin >> p;
    
    Graph g(p+r); // let first r vertices be requsts, nest all be processes

    cout << "\n\nNow we will construct the RAG(Resource allocation Graph) or wait-for graph: \n\n";
    for (int i = 0; i < r; i++)
    {
        cout << "-----------------------------------------------\nEnter number of process requesting resource R" << i << " --\t";
        int n;
        cin >> n;
        cout << "Enter space separated list of " << n << " process requesting resource R" << i << "\n";
        for (int j = 0; j < n; j++)
        {
            int process;
            cin >> process;
            //for maping purpose, we will take process id = total resources + process number being inputted
            g.addEdge(process+r-1, i);
        }
        cout << "Enter number of process holding resource R" << i << " --\t";
        cin >> n;
        cout << "Enter space separated list of " << n << " process holding resource R" << i << "\n";
        for (int j = 0; j < n; j++)
        {
            int process;
            cin >> process;
            g.addEdge(i, process+r-1);
        }
    }

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}

/*
Enter the total number of resources --2
Enter the total number of processes --2


Now we will construct the RAG(Resource allocation Graph) or wait-for graph: 

-----------------------------------------------
Enter number of process requesting resource R0 --       1
Enter space separated list of 1 process requesting resource R0
1
Enter number of process holding resource R0 --  1
Enter space separated list of 1 process holding resource R0
2
-----------------------------------------------  
Enter number of process requesting resource R1 --       1
Enter space separated list of 1 process requesting resource R1
2
Enter number of process holding resource R1 --  1
Enter space separated list of 1 process holding resource R1
1
Graph contains cycle
**/

