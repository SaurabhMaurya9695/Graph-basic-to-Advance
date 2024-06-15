// on the same path node has to visited again then we call a cycle 
// for calling again and again from the same point we have visited thing and for
// path traversal thing wether are we on the same path or not .. we have path array

// in short we have two arrays .. one is visited and another one is path 


`````````````````````````````````````````` DFS ``````````````````````````````````````````````````````
// time : O(V + E) -> Every vertices has single edge 
// space : O(2 n) => O(n);

class Solution {
    
  private:
    bool dfs(int node , vector<int>adj[] , vector<bool> &vis , vector<bool>&path){
        // before going in next mark as true in path as well as mark node visited
        vis[node]  = true ;
        path[node] = true;

        for(auto &nbrs : adj[node]){
            if(vis[nbrs] == false){
                // false means it is not visited 
                if(dfs(nbrs , adj, vis , path) == true){
                    return true;
                }
            }   
            else{
                // if it is already visited && it is in the same path  
                if(path[nbrs] == true){
                    return true ;
                }
            }
        }
        // if they are not in same path then 
        // remove from path 
        path[node] = false;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // we already has given adj list 
        vector<bool> vis(V , false);
        vector<bool> path(V , false);
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0){
                if(dfs(i , adj , vis , path) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

`````````````````````````````````````````` BFS ``````````````````````````````````````````````````````

// using Topo sort and kahn algo 

//   ````````````````````````````````````````````````````````````````````````````````````````````````
                            //  using topoSort 
                            
        bool isCyclic(int V, vector<int> adj[]) {                        
            vector<int> indegree(V , 0);
            for(int i = 0 ;  i < V ; i ++){
                // go for each node and find the indegree for each node 
                for(auto &nbrs : adj[i]){
                    indegree[nbrs] ++ ;
                } 
            }
            
            
            // now we have indegree .. insert those indegree whose value is zero 
            queue<int> q;
            for(int i = 0 ; i < V ; i ++){
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> topoAns ;
            while(!q.empty()){
                int node = q.front();
                q.pop() ;
                topoAns.push_back(node);
                for(auto &nbrs : adj[node]){
                    indegree[nbrs] -- ;
                    if(indegree[nbrs] == 0){
                        q.push(nbrs);
                    }
                }
            }
            
            
            // topoLogical Sort is valid when it has Linear N nodes with u comes before v
            // if topop SIze of == V then it doesn't contain any cycle 
            if(topoAns.size() == V){
                return false;
            }
            else{
                return true;
            }
        }   