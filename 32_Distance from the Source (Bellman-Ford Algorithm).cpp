// we already have Djisktra algo for finding shortest path .. so why we used this algo ?
// so here we know already .. djisktra fails when edge has negative weights
// and Djisktra algo get fell into the loop .. and that algo give us TLE 


// Bellman Ford Algo only work when you have directed graph 

// 1 -> 2 with wt {-2}
// 2 -> 3 with wt {-1}
// 3 -> 1 with wt {2}

// Bellman Ford Algo works when it has negative cycle with wt { -2 -1 + 2} => {-1} 
// edge can be given in any order


// relaxation of edges 

/* 
if(dist[u] + wt < dist[v]){
    dist[v] = dist[u] + wt ;
}
*/

// if we have 5 vertices then for 0 we have already distance 0 so we have to do n -1 iteration 
// relaxation is done N - 1 times 
// in first iterration we are focusing   on  1
// in second iterration we are focusing  on  2
// in third iterration we are focusing   on  3
// in fourth iterration we are focusing  on  4


class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V , 1e8);
        dist[S] = 0 ;
        // so now we have to do V - 1 relaxation 

        // time  :  V * E 
        for(int i = 0 ; i < V ; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] == 1e8){
                    // means if we add anything to it .. this will still be the same 
                    continue;
                }
                else if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt ;
                }
            }
        }
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] == 1e8){
                // means if we add anything to it .. this will still be the same 
                continue;
            }
            else if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1}  ;
            }
        }
        
        return dist ;
    }
};