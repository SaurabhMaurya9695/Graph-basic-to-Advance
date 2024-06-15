// this question is base on Djisktra without pq .. here we are using queue DS 

class Solution {
  public:
    int shortestPath(vector<vector<int>> &arr, pair<int, int> src, 
            pair<int, int> dst) {
        int n = arr.size() ;
        int m = arr[0].size() ;
        vector<vector<int>> vis( n , vector<int>(m , 1e9));
        queue<pair<int ,pair<int, int>>> q ;
        q.push({0 ,src});
        vis[src.first][src.second] = 0 ;
        
        int dx[4] = {-1 ,   0 , +1  , 0};
        int dy[4] = { 0 ,  +1 ,  0  , -1};
        while(!q.empty()){
            pair<int , pair<int,int>> cell = q.front() ;
            int steps = cell.first ;
            int row   = cell.second.first  ;
            int col   = cell.second.second ;
            q.pop() ;
            if(row == dst.first && col == dst.second){
                return steps ;
            }
            
            for(int k = 0 ;k < 4 ; k ++){
                int newRow = row + dx[k];
                int newCol = col + dy[k] ;
                if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0){
                    if(steps + 1 < vis[newRow][newCol] && arr[newRow][newCol] == 1){
                        vis[newRow][newCol] = steps + 1;
                        q.push({steps + 1 , {newRow , newCol}}) ;
                    }
                }
            }
            
        }
        return -1;
        
        
    }
};