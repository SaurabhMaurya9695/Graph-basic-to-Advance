class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        // here we have to use bfs djisktra algo 

        int n = arr.size() ;
        int m = arr[0].size() ;
        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        // this will store the distance / minimum effort 

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,
                            greater<pair<int,pair<int,int>>> > pq;
        pq.push({0, {0 , 0}});
        dist[0][0] = 0 ;

        
        int dx[] = {-1 , 0  , +1 ,  0} ;
        int dy[] = { 0 , +1 ,  0 , -1} ;

        while(!pq.empty()){
            auto  it = pq.top() ;
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop() ;
            
            // means we reached at the end point / destination
            if(row == n - 1 && col == m - 1) {
                return (d) ;
            }
            
            for(int k = 0 ; k < 4; k ++){
                int nr = row + dx[k];
                int nc = col + dy[k] ;
                if(nr < n && nr >=0 && nc < m && nc >= 0){
                    int lastVal = arr[row][col] ;
                    int cellVal = arr[nr][nc] ;

                    // simple bfs here is the main logic just && it was given in question also 
                    // A route's effort is the maximum absolute difference in heights between two       consecutive cells of the route.
                    int distNeeded = max(abs (cellVal - lastVal) , d)  ;
                    if(distNeeded < dist[nr][nc]){
                        dist[nr][nc] = distNeeded ;
                        pq.push({distNeeded , {nr , nc}});
                    }
                    
                }
            }
        }
        return 0;
    }
};