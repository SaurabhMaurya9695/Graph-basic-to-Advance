// link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// main purpose to use PQ because each and every time we have shortest path on which we reached
// this will not work on negatives edges 


// complexity -> O(E log V);
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
        // Code here // already given 
        // from 0 we can go { {1, 1}, {2, 6} }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>   pq ;
        // declared min heap 

        // now we have dist array which we have to return 
        vector<int> dist(V , 1e9);
        dist[src] = 0 ;
        
        // pq will store the distance of src and 
        pq.push({0 , src}) ; 

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            int distance = top.first ;
            int node = top.second ;
            pq.pop() ;
            
            for(auto it : adj[node]){
                int edgeNodeWt = it[1];
                int adjNode = it[0] ;
                // dist[adjNode] = min(dist[adjNode] , edgeNodeWt + distance);
                if(edgeNodeWt + distance < dist[adjNode]){
                    dist[adjNode] = edgeNodeWt + distance ;
                    pq.push({dist[adjNode] , adjNode});
                }
                
            }
        }
        
       return dist;
        
    }
};
