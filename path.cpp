#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <cctype>
using namespace std;

const int INF = INT_MAX;

struct Result {
    vector<int> dist, parent;
};

Result dijkstra(vector<vector<int>>& graph, int src) {
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] <= INF - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    return {dist, parent};
}

string getPath(const vector<int>& parent,
               int src, int dest) {
    vector<int> path;

    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    if (path.empty() || path[0] != src)
        return "No path";

    string s = "";

    for (int i = 0; i < (int)path.size(); i++) {
        if (i > 0) s += " -> ";
        s += char('A' + path[i]);
    }

    return s;
}

int main() {
    const int n = 6;

    // Automatically defined network (A to F)
    vector<vector<int>> graph = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    cout << "NETWORK ROUTING USING DIJKSTRA\n";
    cout << "Nodes: A B C D E F\n\n";

    // Display the automatically generated matrix
    cout << "Cost Matrix:\n    ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << char('A' + i);
    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << char('A' + i) << "   ";
        for (int j = 0; j < n; j++)
            cout << setw(4) << graph[i][j];
        cout << '\n';
    }

    // OUTPUT 1: Routing table
    char startChar;

    cout << "\nEnter starting node (A-F): ";
    cin >> startChar;
    startChar = toupper(startChar);

    int start = startChar - 'A';

    if (start < 0 || start >= n) {
        cout << "Invalid node!\n";
        return 0;
    }

    Result r = dijkstra(graph, start);

    cout << "\n========== ROUTING TABLE ==========\n";
    cout << left << setw(15) << "Destination"
         << setw(30) << "Shortest Path"
         << "Cost\n";

    cout << string(55, '-') << '\n';

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << char('A' + i);

        if (r.dist[i] == INF) {
            cout << setw(30) << "Unreachable" << "INF\n";
        } else {
            cout << setw(30)
                 << getPath(r.parent, start, i)
                 << r.dist[i] << '\n';
        }
    }

    // OUTPUT 2: User-selected shortest paths
    cout << "\n========== PATH FINDER ==========\n";
    cout << "Enter source and destination (e.g. A C).\n";
    cout << "Enter X X to exit.\n";

    char s, d;

    while (true) {
        cout << "\nSource and destination: ";
        cin >> s >> d;

        s = toupper(s);
        d = toupper(d);

        if (s == 'X' && d == 'X')
            break;

        int src = s - 'A';
        int dest = d - 'A';

        if (src < 0 || src >= n ||
            dest < 0 || dest >= n) {
            cout << "Invalid node! Use A-F.\n";
            continue;
        }

        Result ans = dijkstra(graph, src);

        if (ans.dist[dest] == INF) {
            cout << "No path exists.\n";
        } else {
            cout << "Shortest path: "
                 << getPath(ans.parent, src, dest) << '\n';
            cout << "Total cost: "
                 << ans.dist[dest] << '\n';
        }
    }

    cout << "Program terminated.\n";
    return 0;
}




Output:-

Nodes: A B C D E F

Cost Matrix:
       A   B   C   D   E   F
A      0   4   2   0   0   0
B      4   0   1   5   0   0
C      2   1   0   8  10   0
D      0   5   8   0   2   6
E      0   0  10   2   0   3
F      0   0   0   6   3   0

Enter starting node (A-F): A

========== ROUTING TABLE ==========
Destination    Shortest Path                 Cost
-------------------------------------------------------
A              A                             0
B              A -> C -> B                   3
C              A -> C                        2
D              A -> C -> B -> D              8
E              A -> C -> B -> D -> E         10
F              A -> C -> B -> D -> E -> F    13

========== PATH FINDER ==========
Enter source and destination (e.g. A C).
Enter X X to exit.

Source and destination: C F
Shortest path: C -> B -> D -> E -> F
Total cost: 11

Source and destination: E A
Shortest path: E -> D -> B -> C -> A
Total cost: 10
