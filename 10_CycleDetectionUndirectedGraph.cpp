
                                        // BFS 

// time : O(N) + O(N * 2E) 
// space : O(V + 2E);

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int V , vector<int> adj[] , int vis[] , int src ){
        queue<pair<int, int>> q;
        q.push({src , -1}) ; // first node is 0 and it has no parent 
        vis[src] = true;
        
        while(!q.empty()){
            int node = q.front().first ;
            int parent = q.front().second ;
            q.pop() ;
            
            for(auto &neightbour : adj[node]){
                if(vis[neightbour] == false){
                    vis[neightbour] = true;
                    q.push({neightbour , node}) ;
                }
                else {
                    // if it is already visited then you must ensure that visited thing should not be oarent
                    if(neightbour != parent){
                        // means you visited some other node which is not a parent 
                        return true;
                    }
                }
            }
        }
        
        return false ;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // we have already given an adjenceny list .. 
        // 0 -> 1 ,  1 -> {0 , 2, 4} , 2 -> { 1 , 3} , 3 -> {4 , 3} , 4 -> {1 , 3} 
        
        int vis[V] = {0} ;
        
        // code fails when we have multiple components so we need to start checking from each point / vertices 
        for(int i = 0 ; i < V ; i ++){
            if(vis[i] != true){
                if(bfs(V , adj ,vis , i ) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

                                        //DFS

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //Cyclic detection using DFS
    bool iscyclicDFS(int node, int parent, vector<bool> &visited, vector<int> adj[]){
        visited[node]=true;
        for(auto neightbour : adj[node]){
            // jo bhi nbr is agar wo vis nhi hai or wo hmare parent ni hone chhaiye
            if(!visited[neightbour]){
                bool detected = iscyclicDFS(neightbour, node, visited, adj);
                if(detected) return true;
            }
            else if(neightbour != parent) return true;
            
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<bool> visited(V, false);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               // before calling for DFS ..we must ensure that we have to pass parent to avoid cycle with
               // itself parent ..
               bool ans = iscyclicDFS(i, -1, visited, adj); 
               if(ans==1) return true;
           }
           
       }
       return false;
    }
};

