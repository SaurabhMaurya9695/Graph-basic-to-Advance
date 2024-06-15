class DisjointSet {
     
public: 
    vector<int> rank, parent, size;
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet dsu(n);
        int cntExtraEdges = 0 ;
        for(auto x: edge){
            int u = x[0];
            int v = x[1];
            if(dsu.findUPar(u) == dsu.findUPar(v)){
                // if both are connected already and having the same parent 
                cntExtraEdges ++ ;
                // no need to add one extra edge 
            }
            else{
                dsu.unionBySize(u , v);
            }
        }
        
        int connectedComponent = 0 ;
        for(int i = 0 ; i< n ; i ++){
            if(dsu.parent[i] == i){
                connectedComponent ++ ;// they already has the own parent (ultimateParent)
                
            }
        }
        
        int ans = connectedComponent - 1 ; // for MST , n nodes we have n - 1 edges  
        if(cntExtraEdges >= ans ) return cntExtraEdges ;
        else{
            return -1;
        }
    }
};
