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

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int maxi=0;
        DisjointSet d1(n*n);
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==0)continue;
                for(int i=0;i<4;i++)
                {
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                        int node=r*n+c;
                        int node1=nr*n+nc;
                        d1.unionBySize(node,node1);
                    }
                }
            }
        }

        // connected all the components 
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                // if it is one then we don't have to do anything 
                if(grid[r][c]==1)continue;
                set<int>st;
                for(int i=0;i<4;i++)
                {
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                        int node2=nr*n+nc;
                        // we are inserting because if we have 0 then we are moving in all four
                        // drxns and all directions have 1 .. if we store direct parent of node2
                        // then we count one parent many time so we use set to ignore this 
                        st.insert(d1.findUPar(node2));  
                    }
                }
                int totalsize=1;
                for(auto it:st)
                {
                   totalsize+=d1.size[it];
                }
                maxi=max(maxi,totalsize);
            }
        }
        for(int celno=0;celno<n;celno++)
        {
            maxi=max(maxi,d1.size[d1.findUPar(celno)]);
        }
        return maxi;
    }
};