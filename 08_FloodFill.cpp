class Solution {
public:

    void dfs(int i , int j , vector<vector<int>>& arr , int c , vector<vector<bool>> vis , int n , int m , int temp){

        vis[i][j] = true;
        if(arr[i][j] == temp){
            arr[i][j] = c;
        }

        if(i + 1 < n && vis[i + 1][j] == false && arr[i + 1][j] == temp){
            dfs( i + 1 , j , arr , c , vis , n , m , temp);
        }

        if(j + 1 < m && vis[i][j + 1] == false && arr[i][j + 1] == temp){
            dfs( i  , j + 1 , arr , c , vis , n , m , temp);
        }

        if(i - 1 >= 0 && vis[i - 1][j] == false && arr[i - 1][j] == temp){
            dfs( i - 1 , j , arr , c , vis , n , m , temp);
        }

        if(j - 1 >= 0 && vis[i][j - 1] == false && arr[i][j - 1] == temp){
            dfs( i , j - 1 , arr , c , vis , n , m , temp);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int PakdoIskoOrChangeKroIntoColor = arr[sr][sc];
        // dfs(sr , sc , image , color , vis , n , m , PakdoIskoOrChangeKroIntoColor);

        // from here we can start BFS 
        int c = color ;
        queue<pair<int, int >> q ; // pair we use beacuse we have to store {i ,j };
        q.push({sr , sc}) ;
        vis[sr][sc] = true ;

        if(arr[sr][sc] == PakdoIskoOrChangeKroIntoColor ){
            arr[sr][sc] = c;
        }
 
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            vis[i][j] = true;

            if(i + 1 < n && vis[i + 1][j] == false && arr[i + 1][j] == PakdoIskoOrChangeKroIntoColor){
                arr[i + 1][j] = c;
                q.push({i + 1, j});
            }
            
            if(j + 1 < m && vis[i][j + 1] == false && arr[i][j + 1] == PakdoIskoOrChangeKroIntoColor){
                arr[i ][j + 1] = c;
                q.push({i , j + 1});
            }

            if(i - 1 >= 0 && vis[i - 1][j] == false && arr[i - 1][j] == PakdoIskoOrChangeKroIntoColor){
                arr[i  - 1 ][j] = c;
                q.push({i - 1 , j });
            }

            if(j - 1 >= 0 && vis[i][j - 1] == false && arr[i][j - 1] == PakdoIskoOrChangeKroIntoColor){
                arr[i ][j - 1] = c;
                q.push({i , j - 1});
            }

        }


        return arr ;
    }
};