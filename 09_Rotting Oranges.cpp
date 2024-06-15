
// in this question ..  dfs not worked there because there are multisource of rotten oranges ..
// in a grid there can be multiple rotten oranges present 


class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // 0 means -> empty , 1 means fresh apple , 2 means rotten orange 
        queue<pair<pair< int ,int > ,int>> q ;
        // {{row , col} , time };
        vector<vector<bool>> vis(n , vector<bool> (m , false));
        int cntFresh = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i ,j} , 0});
                    vis[i][j] = 2 ;
                }
                else{
                    vis[i][j]  = 0;
                }

                if(grid[i][j] == 1) cntFresh ++ ;
            }
        }
        
        const int x4[4] = {1, -1, 0, 0};
        const int y4[4] = {0, 0, -1, 1};


        int cntFreshTouched =  0;
        int ans = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            ans = max(ans , t);
            //  so we have multiple source so we should keep track from which path we are getting max time 

            
            // make call in all four directions
            for(int i = 0 ; i < 4 ; i ++){
                int newR = x4[i] + r;
                int newC = y4[i] + c;

                if((newR < n && newR >=0 && newC < m && newC >= 0) && vis[newR][newC] == false && grid[newR][newC] != 2 && grid[newR][newC] == 1){
                    q.push({{newR , newC} , t + 1});
                    vis[newR][newC] = 2;
                    cntFreshTouched ++ ;
                }
            }
        }

        if(cntFreshTouched != cntFresh){
            return -1;
        }
        return ans ;
        
    }
};