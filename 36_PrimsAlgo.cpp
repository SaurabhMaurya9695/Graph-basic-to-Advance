
// E log E
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // MST is means for N nodes and N - 1 edges 
        vector<bool> vis(V , false);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        
        // we don't need the parent RN
        pq.push({0 , 0}); // {weight , node } 
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop();
            int wt = it.first;
            int node = it.second ;
            
            
            if(vis[node] == true) continue ;
            vis[node] = true;
            sum += wt ;
            for(auto nbrs : adj[node]){
                int adjNode = nbrs[0];
                int edgeWt = nbrs[1];
                if(vis[adjNode] == false){ //if that node is not. visited 
                    pq.push({edgeWt , adjNode});
                }
            }
            
        }
        return sum ;
    }
};