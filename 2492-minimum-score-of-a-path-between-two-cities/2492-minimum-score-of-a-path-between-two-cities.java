import java.util.*;

class Solution {

    int ans = Integer.MAX_VALUE;

    public int minScore(int n, int[][] roads) {

        List<List<int[]>> adj = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        // Build the graph
        for (int[] road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj.get(u).add(new int[]{v, d});
            adj.get(v).add(new int[]{u, d});
        }

        boolean[] visited = new boolean[n + 1];

        dfs(1, adj, visited);

        return ans;
    }

    private void dfs(int node, List<List<int[]>> adj, boolean[] visited) {

        visited[node] = true;

        for (int[] edge : adj.get(node)) {

            int next = edge[0];
            int dist = edge[1];

            ans = Math.min(ans, dist);

            if (!visited[next]) {
                dfs(next, adj, visited);
            }
        }
    }
}