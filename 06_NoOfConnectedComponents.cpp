
// link : https://www.geeksforgeeks.org/problems/number-of-provinces/
// link : https://leetcode.com/problems/number-of-provinces/description/


// Time ->  O(V * V) + O(V) + O(2 * E) ;
// space -> O(V * V) + O(V) + O(N) 

class Solution {
  public:
    
    int connectedComponent = 0;
    void dfs(int node , vector<int> adjLst[] ,int vis[] ){
        
        vis[node] = 1 ;
        for(auto & neighbour : adjLst[node]){
            if(vis[neighbour] == 0){
                dfs(neighbour , adjLst , vis);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // convert adj matrix into adj list 
        vector<int> adjLst[V];
        for(int i = 0 ; i < V ; i ++){
            for(int j =0 ; j < V ; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        for(int i = 0 ; i< V ; i ++){
            if(vis[i] == false){
                connectedComponent ++ ;
                dfs(i , adjLst , vis);
            }
        }
        
        return connectedComponent; 
    }
};

````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// BFS
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // convert adj matrix into adj list 
        vector<int> adjLst[V];
        for(int i = 0 ; i < V ; i ++){
            for(int j =0 ; j < V ; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int ans = 0 ;
        for(int i = 0 ; i< V ; i ++){
            if(vis[i] == false){
                ans ++ ;
                vis[i] = true;
                queue<int > q;
                q.push(i);
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    
                    for(auto x : adjLst[front]){
                        if(vis[x] == false){
                            q.push(x);
                            vis[x] = true;
                        }
                    }
                }
            }
        }
        return ans ;
        
       
    }
};
