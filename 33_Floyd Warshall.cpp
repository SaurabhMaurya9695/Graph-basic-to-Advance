// in djisktra we can only tell from src to destination the shortest path 
// but here we can tell from any node to any node what is the shortest path 

// This is also called MULTISOURCE SHORTEST PATH ALGO
// to reach at the destination we can go to every vertex 

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&arr){
	    int n = arr.size() ;
	    for(int i = 0 ; i < n ; i ++){
	        for(int j = 0 ; j < n ; j ++){
	            if(arr[i][j] == -1){
	                arr[i][j] = 1e8 ;
	            }
	            if(i == j) {
	                // cost to itself is zero 
	                arr[i][j] = 0; // this means diagonal 
	            }
	        }
	    }
	    
	    for(int via = 0 ; via < n ; via ++){
	        for(int i = 0 ; i < n ; i ++){
    	        for(int j = 0 ; j < n ; j ++){
    	            int currentCost = arr[i][j];
    	            int viaCost = arr[i][via] + arr[via][j];
    	            arr[i][j] = min(currentCost , viaCost);
    	        }
    	    }
	    }
	    
	    
	    for(int i = 0 ; i < n ; i ++){
	        for(int j = 0 ; j < n ; j ++){
	            if(arr[i][j] == 1e8){
	                // if it is not reachable then it is -1 
	                arr[i][j] = -1 ;
	            }
	        }
	    }
	    
	    
	    
	}
};
