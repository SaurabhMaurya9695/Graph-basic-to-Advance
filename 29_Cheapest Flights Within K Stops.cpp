// here the main clue is level .. at the time when level == k you have to stop it 


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            int wt = arr[i][2];

            adj[u].push_back({v, wt});
        }

        // now we have an adj list available now
        queue<pair<int, int>> q;
        q.push({src, 0}); // {src , dist};
        vector<int> distance(n , 1e9);
        distance[src] = 0;

        int level = 0;
        while (!q.empty() && level <= k) {
            int size = q.size();
            while (size--) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();

                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int edgeWt  = it.second;
                    if (distance[adjNode] > dist + edgeWt ) {
                        distance[adjNode] = dist + edgeWt;
                        q.push({adjNode, dist + edgeWt});
                    }
                }

            }
            level++;
        }

        return ((distance[dst] == 1e9) ? -1 : distance[dst]);
    }
};