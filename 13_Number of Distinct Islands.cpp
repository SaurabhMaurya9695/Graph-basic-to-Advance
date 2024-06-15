// here we have to tell how many of then has the same shape .. so we have an example 
1 1 0 0
1 0 1 1
0 0 1 0

// here for coordinate for top left corner : {0 ,0} {0 , 1} {1 , 0}
// here for coordinate for below  : {1 ,2} {1 , 3} {2 , 2}
// here thing to notice is if we subtract then front index from there it started dfs then its easy to track 
// [{0 ,0} - {0 ,0}] ,[ {0 , 1} - {0 , 0}], [ {1 ,0} , {0 , 0}]
// [{1 ,2} - {1, 2}] ,[ {1 , 3} - {1 , 2}], [ {2 , 2} , {1 , 2}] = {0 ,0} {0 , 1} {1 , 0} 
// now we have matching shapes now you can store in set 


// time : O(n * m) + O(n * m * 4) + O(log(n * m))


class Solution {
    public :    
    void dfs(int i , int j , vector<vector<bool>>& vis , vector<vector<int>> & grid
    , vector<pair<int,int>> & vec , pair<int , int > current_idx){
        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[i][j] = true;
        vec.push_back({i - current_idx.first  , j - current_idx.second });
        int dx[4] = {-1,0,+1,0};
        int dy[4] = {0,-1,0,+1};
        for(int k =0 ; k < 4 ; k ++){
            int newI = i + dx[k];
            int newJ = j + dy[k];
            if(newI < n && newI >= 0 && newJ < m && newJ >=0 &&
                vis[newI][newJ] == false && grid[newI][newJ] == 1){
                dfs(newI , newJ , vis , grid , vec , current_idx) ;
            }
        }
    }
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        
        set<vector<pair<int,int>>> st ;
        
        for(int i = 0; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    vector<pair<int,int>> vec ;
                    pair<int , int> current_idx ={i , j } ;
                    dfs(i , j , vis , grid , vec ,current_idx );
                    st.insert(vec);
                }
            }
        }
        
        return st.size() ;
    }
};