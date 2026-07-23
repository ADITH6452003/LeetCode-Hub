class Solution {
public:
void bfs(vector<int> adj[], int src, vector<bool>& visited){
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            

            for (int x : adj[node]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), m = isConnected[0].size();

    vector<int> adj[n + 1];
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bfs(adj, i, vis);
            cnt++;
        }
    }

    return cnt;
}
};