// question link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// space -> O(3 * N) ==> O(N);
// time -> O(N) + O(2 * E);

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       // already adjency list has been given to us
       // so we have to just focus on the BFS
       int vis[V] = {0} ; // making all of them as false
       vis[0] = 1 ;
       
       // inserted the first value in queue 
       queue<int> q ;
       q.push(0);
       
       vector<int> bfs ;
       
       while(!q.empty()){
          int frontNode = q.front() ;
          q.pop() ;
          bfs.push_back(frontNode);
          for(auto x : adj[frontNode]) // go infront of node and add all its element
          {
              if(vis[x] == 0){ // if it is not visited
                vis[x] = 1;
                q.push(x);
              }    
              else{
                  continue ;
              }
          }
          
       }
       return bfs ;
       
    }
};