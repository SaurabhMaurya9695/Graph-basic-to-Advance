// calculate indegree of all nodes 
        vector<int> degree(n , 0);
        for(auto x : roads){
            int u = x[0];
            int v = x[1];
            degree[u] ++ ;
            degree[v] ++ ;
        }
