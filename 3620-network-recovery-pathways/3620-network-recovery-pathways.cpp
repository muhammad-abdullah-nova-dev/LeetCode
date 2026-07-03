class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);

        int mx = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indeg[v]++;
            mx = max(mx, w);
        }

        // Topological Order
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> topo;
        topo.reserve(n);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto &[v, w] : adj[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {
            const long long INF = (1LL << 60);
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                // Intermediate nodes must be online
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, w] : adj[u]) {
                    if (w < limit) continue;

                    if (v != n - 1 && !online[v]) continue;

                    if (dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0, hi = mx;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};