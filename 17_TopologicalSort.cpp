// Topo is based on DAC(Directed Acyclic graph) ;
// Linear ordering of vertices such that there is an edge b/w u & v , u appera before v in that ordering 

// link : https://www.geeksforgeeks.org/problems/topological-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution
{
    private :
    void dfs(int node , vector<bool> &vis , vector<int> adj[] , stack<int> &stk){
        vis[node] = true ;
        for(auto &nbrs : adj[node]){
            if(vis[nbrs] == false){
                dfs(nbrs , vis , adj , stk);
            }
        } 
        
        // if there is no furture calls happen then this is our ans 
        stk.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V , false) ;
	    vector<int> ans ;
	    stack<int> stk ;
	    for(int i = 0 ; i < V ; i ++){
	        if(vis[i] == false){
	            dfs(i , vis , adj , stk);
	        }
	    }
	    
	    while(!stk.empty()){
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans ;
	}
};
