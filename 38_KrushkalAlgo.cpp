// 1:  sort all the edges according to weight 
// 2 : Use DSU and those having the same parent those are not belonging to the same component
// 3 : if parent[node] != parent[comingNode] then add them


class DisjointSet {
    private:
        vector<int> size;
        vector<int> parent;
        
    public:
        DisjointSet(int V) {
            size.resize(V + 1, 0);
            parent.resize(V + 1);
            
            for (int i = 0; i < V + 1; ++i) {
                parent[i] = i;
            }
        }
        
        int findUParent(int node) {
            if (parent[node] == node) {
                return node;
            }
            
            return (parent[node] = findUParent(parent[node]));
        }
        
        void unionBySize(int u, int v) {
            // u ---> v
            int ult_pu = findUParent(u);
            int ult_pv = findUParent(v);
            
            if (ult_pu == ult_pv) return;
            
            if (size[ult_pu] < size[ult_pv]) {
                parent[ult_pu] = ult_pv;
                size[ult_pv] += size[ult_pu];
            } else {
                parent[ult_pv] = ult_pu;
                size[ult_pu] += size[ult_pv];
            }
        }
        
        bool sameComponent(int u, int v) {
            return (findUParent(u) == findUParent(v));
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; ++i) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mst_wt = 0;
        
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (!ds.sameComponent(u, v)) {
                mst_wt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mst_wt;
    }
};