// link : https://leetcode.com/problems/find-eventual-safe-states/


class Solution {
public:

    bool cyclic(int node , vector<vector<int>>& adj , vector<bool > & vis ,  vector<bool> & path , vector<bool> & check){
        vis[node] = true ;
        path[node] = true;
        // we enter in node x then we initially says this is contain cycle 
        check[node] = false;

        // call to nbrs 
        for(auto & nbrs : adj[node]){
            if(vis[nbrs] == false){
                if(cyclic(nbrs , adj , vis , path , check) == true){
                    check[node] = false;
                    return true;
                }
                
            }
            else{
                if(path[nbrs] == true){
                    // we came across same path 
                    check[node] = false; // if we got some cycle then we can say that this is not part of our ans 
                    return true;
                }
            }
        }

        // before going back 
        check[node] = true; // if the above node not contain cycle then it should be our ans 
        path[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        // eventually we have to return a node which don't have cycle ;
        int n = adj.size() ;
        //. we have already given a adj list 
        vector<bool> vis(n , false) , path(n , 0) ,check(n , false) ;
        vector<int> ans ;
        for(int i = 0 ; i< n; i ++){
            if(vis[i] == false){
                cyclic(i , adj , vis , path , check) ;
            }
        }

        for(int i = 0 ; i< n ; i ++){
            if(check[i] == true){
                ans.push_back(i);
            }
        }

        return ans ;
    }
};


``````````````````````````````````````BFS`````````````````````````````````````````````````````````````````````````````

    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        // how can we know whether we have to reverse a graph or not to use topoSort
        // so if you calculate an indegree of a graph then you can see that terminalNodes/safeNodes having indegree zero 
        // so for terminal nodes indegree zero then you pushed into the queue .
        // then goes to its neighbours and reduce its indegree to -=1 . you can see at some point you are not able to make the call then you should reliased if you reverese the edges then
        // you can use topoSort here easily
        int V = g.size() ;
        vector<int> adj[V] ;
        vector<int> indegree(V , 0);
	    for(int i =0 ;  i< V ; i ++){
	        for(auto &nbrs : g[i]){
                adj[nbrs].push_back(i);
	            indegree[i] ++ ;
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
	    vector<bool> safeNodes(V, false);
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        
	        // we push this node into topoAns because its indegree is zero 
	        safeNodes[node] = true;
	        
	        // now we have a node whose indegree is zero 
	        // now traverse to its neighbour and reduce its indegree to zero 
	        for(auto &nbrs : adj[node]){
	            indegree[nbrs] -- ;
	            if(indegree[nbrs] == 0){
	                q.push(nbrs);
	            }
	        }
	        
	    }

        vector<int>ans ;
        for(int i = 0  ; i < V ; i++){
            if(safeNodes[i] == true){
                ans.push_back(i);
            }
        }
	    
	    return ans ;

    }