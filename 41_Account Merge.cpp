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
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size() ;
        unordered_map<string, int> mp;
        DisjointSet dsu(n) ;
        // we have now n sized dsu 
        // initially we have n node which are pointing to itself
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 1 ; j < arr[i].size() ; j ++ ){
                string accountName = arr[i][j];
                if(mp.find(accountName) != mp.end()){
                    // if that name already exist in map this is already part of some node 
                    // this time we have to join it 
                    dsu.unionBySize(i , mp[accountName]);
                }
                else{
                    mp[accountName] = i ;
                }
            }
        }
        
        // now this time some nodes are pointing to its parent 
        // {0 <- 3} {1} {2 <- 4} {5}
        // parent of 3 is 0 and for the parent of 1 is itself 1 
        
        // now 0 means John , 1 means Mary , 2 means John in the given example 
        vector<string> mergedMail[n];
        for(auto &[l, r] : mp){
            string emails = l ;
            // int node = r ; // instead of finding its node find its parent 
            int node = dsu.findUPar(r);
            mergedMail[node].push_back(emails);
        }
        
        // now we have mergedMail 
        // every index stores 
        // 0 -> {0 has merged List of emails}
        // 1 -> {1 has merged List of emails}
        // .
        // . so on
        
        // now we want vector<vector<string>> ans 
        vector<vector<string>> ans ;
        for(int i = 0 ; i< n ; i ++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin() , mergedMail[i].end());
            vector<string> temp ;
            temp.push_back(arr[i][0]);
            for(auto x: mergedMail[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans ;
        
        
    }
};