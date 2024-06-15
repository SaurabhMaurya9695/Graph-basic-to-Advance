class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // this is just dijisktra base problem ..in this just have to findout the parent 
        // we have to create adjList
        vector<pair<int,int>> adj[n] ;
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        
        // now we have undirected graph 
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        pq.push({0 , 1}) ;
        
        vector<int> dist(n + 1 , 1e9) ;
        // everything is same as Dijisktra Algo but slightly difference 
        vector<int> parent( n + 1) ;
        dist[1] = 0;

        // you have to think from where we came 
        for(int i = 1; i <= n ; i ++){
            // currently we came from itself
            parent[i] = i ; 
        }
        
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int Node = pq.top().second;
            pq.pop() ;
            
            for(auto nbrs : adj[Node]){
                int adjNode = nbrs.first;
                int weight = nbrs.second ;
                if(distance + weight < dist[adjNode]){
                    dist[adjNode] = distance + weight ;
                    pq.push({distance + weight , adjNode});

                    // here we just update form where we came ;
                    parent[adjNode] = Node ;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1} ; // means we aren't able to reach the destination 

        vector<int> ans ;
        int lastNode  = n ;
        // if we are not equal to itself means we came from somewhere so just chase that number
        
        while(parent[lastNode] != lastNode){
            ans.push_back(lastNode);
            lastNode = parent[lastNode] ;
        }
        ans.push_back(1);
        reverse(ans.begin() , ans.end());
        return ans ;
        
    }
};
