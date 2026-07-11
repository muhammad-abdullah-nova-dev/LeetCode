class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
             vector<int>& component) {
        vis[node] = true;
        component.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfs(i, adj, vis, component);

                int vertices = component.size();
                int edgeCount = 0;

                for (int node : component) {
                    edgeCount += adj[node].size();
                }

                edgeCount /= 2;

                if (edgeCount == vertices * (vertices - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};