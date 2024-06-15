// Topo is based on DAC(Directed Acyclic graph) ;
// Linear ordering of vertices such that there is an edge b/w u & v , u appera before v in that ordering 

// link : https://www.geeksforgeeks.org/problems/topological-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


// inserted node in queue who has indegree zero 

class Solution
{
	public:
    //Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    
	    
	    return topoAns ;
	}
};

