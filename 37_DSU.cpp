// if we have graph  like this

// 1 - 2 - 3 - 4
// 5 - 6 - 7

// so our is like .. whether they belong to the same component or not ?

// brute force is to make a vis array of V and start a traversal .. O(V + E)

// with the help of DSU we can check whether they belong to the same component or not 

// DSU gives us two func -> findParent() and union() { this union can be find in two ways 
// 1 : by rank & 2 : by size }

                    // pseudocode
                    // 1 : find ultimate Parent of u and v 
                    // 2 : find rank of u and v
                    // 3 : connect smaller rank to larger rank 



#include <bits/stdc++.h>
using namespace std;
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
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}
