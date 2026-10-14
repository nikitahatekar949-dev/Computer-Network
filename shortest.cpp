#include <iostream>
#include <climits>
using namespace std;

int main()
{
    const int N = 7;
    int graph[N][N] = {
        {0, 4, 2, 0, 0, 0, 0},
        {4, 0, 1, 5, 0, 0, 0},
        {2, 1, 0, 8, 10, 0, 0},
        {0, 5, 8, 0, 2, 6, 0},
        {0, 0, 10, 2, 0, 3, 7},
        {0, 0, 0, 6, 3, 0, 1},
        {0, 0, 0, 0, 7, 1, 0}
    };

    int dist[N], parent[N];
    bool visited[N] = {false};

    int source = 0;  // Starting node: 1

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < N; count++)
    {
        int u = -1;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Node\tDistance\tShortest Path\n";

    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "\t";

        if (dist[i] == INT_MAX)
        {
            cout << "No path\t-\n";
            continue;
        }

        cout << dist[i] << "\t\t";

        int path[N], size = 0;
        int current = i;

        while (current != -1)
        {
            path[size++] = current;
            current = parent[current];
        }

        for (int j = size - 1; j >= 0; j--)
        {
            cout << path[j] + 1;
            if (j > 0)
                cout << " -> ";
        }

        cout << endl;
    }

    return 0;
}


Outpu:-


Node    Distance        Shortest Path
1       0               1
2       3               1 -> 3 -> 2
3       2               1 -> 3
4       8               1 -> 3 -> 2 -> 4
5       10              1 -> 3 -> 2 -> 4 -> 5
6       13              1 -> 3 -> 2 -> 4 -> 5 -> 6
7       14              1 -> 3 -> 2 -> 4 -> 5 -> 6 -> 7