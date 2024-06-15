class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    // finding ultimate parent for a node using path compression 
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    // 
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        // if they both belong to same parent no need to do nothing
        if(ulp_u == ulp_v) return; 

        // add smaller rank to larger rank 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            // if both parent has the same rank then we can attach to anyone 
            parent[ulp_v] = ulp_u; 

            // and it will increase the rank by 1 
            rank[ulp_u]++; 
        }
    }


    // union by size help us to find the component size at a given point
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 



class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &arr) {
        int vis[n][m];
        memset(vis , 0, sizeof vis);
        DisjointSet dsu(n * m);
        vector<int> ans ;
        int cnt = 0 ;
        for(auto x : arr){
            int row = x[0] , col = x[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] =1 ;
            cnt ++ ; // counter increase for itself
            // now go around its edges and check if any of them neighbour is visited then 
            // reduce count by 1
            
            int dx[4]= {-1 ,  0 ,  0 , +1 };
            int dy[4]= {0  , +1 , -1  , 0 };
            
            for(int k = 0 ; k < 4; k ++){
                int newr = row + dx[k] ;
                int newc = col + dy[k];
                if(newr < n && newr >=0 && newc < m && newc >= 0){
                    if(vis[newr][newc] == 1) {
                        int nodeNo = row * m + col ;
                        int adjCol = newr * m + newc ; 
                        if(dsu.findUPar(nodeNo) != dsu.findUPar(adjCol)){
                            cnt -- ;
                            dsu.unionBySize(nodeNo , adjCol);
                        }
                        
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans ;
        
        
    } 
};