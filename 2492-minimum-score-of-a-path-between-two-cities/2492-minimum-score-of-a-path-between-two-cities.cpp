class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[a] = b;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &r : roads)
            unite(r[0], r[1]);

        int root = find(1);
        int ans = INT_MAX;

        for (auto &r : roads) {
            if (find(r[0]) == root)
                ans = min(ans, r[2]);
        }

        return ans;
    }
};