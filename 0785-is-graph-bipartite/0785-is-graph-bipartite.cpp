class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!bfs(graph, vis, i, 1))
                    return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, vector<int>& vis, int source,
             int col) {
        vis[source] = col;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it : graph[curr]) {
                if (!vis[it]) {
                    vis[it] = 3 - vis[curr];
                    q.push(it);
                } else if (vis[it] == vis[curr]) {
                    return false;
                }
            }
        }
        return true;
    }
};