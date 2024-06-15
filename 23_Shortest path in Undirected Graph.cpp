// here we have to go with bfs 

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& arr, int N,int M, int src){
        
        vector<int> adj[N] ;
        for(auto it : arr){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<int>dist(N , 1e9);
        
        // initiatlly src having distance zero 
        q.push(src);
        dist[src] = 0 ;

        while(!q.empty()){
            int node = q.front() ;
            q.pop();
            
            // go to its nbrs 
            for(auto it : adj[node]){
                // if you have value 10 and going to its nbrs value came to be 9 then you should
                // take lesser value 
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1 ;
                    q.push(it);
                }
            }
        }
        
        vector<int> ans (N , -1);
        for(int i = 0 ; i < N ; i ++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans ;
        
        
    }
};
