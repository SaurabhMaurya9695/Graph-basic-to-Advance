class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        // this is just reverse of topo sort order 
        vector<int> adj[N] ;
	    for(int i = 0 ; i< arr.size() ; i ++){
	        adj[arr[i][0]].push_back(arr[i][1]);
	    }
	    
	    int V = N ;
	    
	    // we can solve this question using two way ..
	    // if there is no cycle then we can say there always be ans is yes 
	    // or you can solve it using topological way 
	    
	    // if we have (u , v) then u always comes before v
	    
	    vector<int> indegree(V , 0);
	    for(int i =0 ;  i< V ; i ++){
	        for(auto nbrs : adj[i]){
	            indegree[nbrs] ++ ;
	        }
	    }
        
	    // insert those indegree whose indegree is zero 
	    queue<int> q ;
	    for(int i = 0 ; i< V ; i ++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    // atleast one indegree has to be inserted to start BFS using kahn algo 
	    vector<int> topoAns;
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        
	        // we push this node into topoAns because its indegree is zero 
	        topoAns.push_back(node); 
	        
	        // now we have a node whose indegree is zero 
	        // now traverse to its neighbour and reduce its indegree to zero 
	        for(auto &nbrs : adj[node]){
	            indegree[nbrs] -- ;
	            if(indegree[nbrs] == 0){
	                q.push(nbrs);
	            }
	        }
	        
	    }
        
        if(topoAns.size() != V) return {} ;
        else{
            reverse(topoAns.begin() , topoAns.end());
        }
        return topoAns;
    }
};