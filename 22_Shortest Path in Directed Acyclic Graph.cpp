// do a topoSort on DAG and find the topoSort array {u comes before v};

class Solution {
  
  private :
    void topoSort(int node , vector<pair<int,int>> adj[] , vector<bool>& vis , stack<int> &stk){
        // now mark vis 
        vis[node] = true ;
        for(auto it  : adj[node]){
            int u  = it.first;
            if(vis[u] == false){
                topoSort(u , adj , vis, stk);
            }
        }
        
        // before going back put node into stack
        stk.push(node);
    }
      
  public:
    vector<int> shortestPath(int V ,int N, vector<vector<int>>& arr){
        // we have  to create adjList with {u,v,wt}
        vector<pair<int, int>> adj[V] ;
        for(int i = 0 ; i < N ; i ++){
            int u  = arr[i][0];
            int v  = arr[i][1];
            int wt = arr[i][2];
            adj[u].push_back({v , wt});
        }
        
        // now we have adjList with weight .. now find topoSort 
        vector<bool> vis(V , false) ;
        stack<int> stk;
        for(int i = 0 ; i < V ; i ++){
            if(vis[i] == false){
                topoSort(i , adj , vis , stk);
            }
        }
        
        // now after end of topoSort we have nodes in stack
        vector<int> dist(V ); 
        for(int i = 0 ; i < V ; i ++) dist[i] = 1e9 ;
        dist[0] = 0 ;
        while(!stk.empty()){
            int node = stk.top() ;
            stk.pop();
            for(auto &it : adj[node]){
                int v  = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
                
            }
        }
        
        return dist ;
        
    }
};
