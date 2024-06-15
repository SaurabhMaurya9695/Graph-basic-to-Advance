
// border se dfs kro ... border se jitne bhi 1 connected hongy in four direction unko 0 mark kro 
// in last check kr lo kitne 1 hai .. simple

class Solution {
public:

    int m, n;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;
        
        grid[r][c] = 0;
        
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            // Last column.
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
            // Last row.
            if (grid[m - 1][i] == 1) {
                dfs(grid, m - 1, i);
            }
        }
        
        
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        
        return count;
    }
};


````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int row,int col,int n,int m, vector<vector<int>> &visited, vector<vector<int>> &grid){
        visited[row][col] = 1;

        for(int k = 0;k<4;k++){
            int nrow = row + dx[k];
            int ncol = col + dy[k];

            if(nrow >= 0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,n,m,visited,grid);
            }
        }
        
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && ( i==0 || i==n-1 || j==0 || j==m-1)){
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;

    }
};

`````````````````````````````````````````` BFS ``````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    int m, n;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;
        
        grid[r][c] = 0;
        
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        
    }

    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        queue<pair<int, int >> q;
        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1) {
                // dfs(grid, i, 0);
                // bfs(grid, i, 0,  vis);
                q.push({i , 0});
                vis[i][0] = true ;
            }
            // Last column.
            if (grid[i][n - 1] == 1) {
                // dfs(grid, i, n - 1);
                // bfs(grid, i, n - 1 , vis);
                q.push({i , n - 1});
                vis[i][n - 1] = true ;
                
            }
        }
            
        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1) {
                // dfs(grid, 0, i);
                // bfs(grid, 0, i , vis);
                q.push({0 , i}) ;
                vis[0][i] = true ;
            }
            // Last row.
            if (grid[m - 1][i] == 1) {
                // dfs(grid, m - 1, i);
                // bfs(grid, m - 1, i , vis);
                q.push({m - 1 , i});
                vis[m - 1][i] = true ;
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while (!q.empty()){
            int i = q.front().first ;
            int j = q.front().second ;
            q.pop();
            for(int k = 0 ; k < 4;  k++){
                int newR = i + dx[k];
                int newC = j + dy[k];
                if(newR < m && newR >= 0 && newC < n && newC >= 0 && vis[newR][newC] != true && grid[newR][newC] == 1){
                    q.push({newR , newC});
                    vis[newR][newC] = true ;
                }
            }
        }
        
        
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    count += 1;
                }
            }
        }
        
        return count;
    }
};