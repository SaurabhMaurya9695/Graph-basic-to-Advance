class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans ;
    void dfs(int node , vector<bool> &vis , vector<int> adj[] ){
        vis[node] = true;
        ans.push_back(node);
        for(auto neighbour : adj[node]){
            if(vis[neighbour] == false){
                dfs(neighbour , vis , adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V + 1 , false);
        dfs(0 , vis , adj);
        return ans ;
    }
};