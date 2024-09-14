class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<int>& col, int node,
             int color) {
        col[node] = color;
        for (auto neighbor : graph[node]) {
            if (col[neighbor] == 0) {
                if (!DFS(graph, col, neighbor, 3 - color)) {
                    return false;
                }
            } else if (col[neighbor] == col[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, 0);
        for (int i = 0; i < n; ++i) {
            if (col[i] == 0) {
                if (!DFS(graph, col, i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};
