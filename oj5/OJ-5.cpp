#include <iostream>
#include <vector>

using namespace std;

const int INF = 2147483647; // Equivalent to numeric_limits<int>::max()

struct Edge {
    int to, weight;
};

int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        graph[a].push_back({b, p});
    }

    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    vector<pair<int, int>> pq;
    pq.push_back({0, start});

    while (!pq.empty()) {
        int min_dist = INF;
        int min_index = -1;
        for (int i = 0; i < pq.size(); ++i) {
            if (pq[i].first < min_dist) {
                min_dist = pq[i].first;
                min_index = i;
            }
        }

        int current_dist = pq[min_index].first;
        int current_node = pq[min_index].second;
        pq.erase(pq.begin() + min_index);

        if (current_dist > dist[current_node]) {
            continue;
        }

        for (const Edge& edge : graph[current_node]) {
            int new_dist = current_dist + edge.weight;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                pq.push_back({new_dist, edge.to});
            }
        }
    }

    cout << dist[end] << endl;

    return 0;
}