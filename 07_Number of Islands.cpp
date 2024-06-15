class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        vis[row][col] = 1;
        int nodeR = row;
        int nodeC = col;
        if(nodeC+1 < grid[0].size() && grid[nodeR][nodeC+1] == '1' && !vis[nodeR][nodeC+1]){
            dfs(nodeR, nodeC + 1, grid, vis);
        }
        if(nodeR+1 < grid.size() && grid[nodeR+1][nodeC] == '1' && !vis[nodeR+1][nodeC]){
            dfs(nodeR + 1, nodeC, grid, vis);
        }
        if(nodeC-1 >= 0 && grid[nodeR][nodeC-1] == '1' && !vis[nodeR][nodeC-1]){
            dfs(nodeR, nodeC - 1, grid, vis);
        }
        if(nodeR-1 >= 0 && grid[nodeR-1][nodeC] == '1' && !vis[nodeR-1][nodeC]){
            dfs(nodeR - 1, nodeC, grid, vis);
        }
    }   

````````````````````````````````````````````````````````````````````````````````````````````````````````

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        queue<pair<int, int>> q;
        q.push({row, col});

        vis[row][col] = 1;
        while(!q.empty()){
            int nodeR = q.front().first;
            int nodeC = q.front().second;
            q.pop();

            if(nodeC+1 < grid[0].size() && grid[nodeR][nodeC+1] == '1' && !vis[nodeR][nodeC+1]){
                vis[nodeR][nodeC+1] = 1;
                q.push({nodeR, nodeC+1});
            }
            if(nodeR+1 < grid.size() && grid[nodeR+1][nodeC] == '1' && !vis[nodeR+1][nodeC]){
                vis[nodeR+1][nodeC] = 1;
                q.push({nodeR+1, nodeC});
            }
            if(nodeC-1 >= 0 && grid[nodeR][nodeC-1] == '1' && !vis[nodeR][nodeC-1]){
                vis[nodeR][nodeC-1] = 1;
                q.push({nodeR, nodeC-1});
            }
            if(nodeR-1 >= 0 && grid[nodeR-1][nodeC] == '1' && !vis[nodeR-1][nodeC]){
                vis[nodeR-1][nodeC] = 1;
                q.push({nodeR-1, nodeC});
            }
        }
    }

````````````````````````````````````````````````````````````````````````````````````````````````````````
    int numIslands(vector<vector<char>>& grid) {
        // we just have to find the connected component .. means every time if we get 
        // the value is not visited then this should be our connected components .

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis( n , vector< bool > ( m , 0));

        int connectedComponenet = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    connectedComponenet++;
                    // dfs(row, col, grid, vis);
                    bfs(row , col , grid , vis);
                }
            }
        }
        return connectedComponenet;
    }
};


````````````````````````````````````````````````````````````````````````````````````````````````````````