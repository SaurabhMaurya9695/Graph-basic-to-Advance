// we have to color graph with 2 colors with no adjacent nodes

// Linear graph with no cycle always bipartite 

// any graph has odd length cycle never be bipartite
class Solution {
private:
    bool bfs(vector<vector<int>>& graph,vector<int>& color,int sv){
        queue<int> q;
        q.push(sv);
        color[sv]=0;
        while(!q.empty()){
            int t=q.front();
            int c=color[t];
            q.pop();
            for(auto x:graph[t]){
                 // abhi mai nbrs pe hu iska color -1 hai mtlb ye colored ni hai 
                    // so we can color this with opposit color
                    
                if(color[x]==-1){
                    color[x]=!c;
                    q.push(x);
                }
                else if(color[x]==c){
                    return false;
                }
            }
        }
        return true;
    }


    bool dfs(vector<vector<int>>& graph , vector<int> &color , int node , int rang){
        color[node] = rang ; // colored first node with 0 you can color with 1 also .
        for(auto &nbrs : graph[node]){
            if(color[nbrs] == -1){
                // means it is not colored ;
                if(dfs(graph , color , nbrs , !rang) == false) return false;
            }
            if(color[nbrs] == color[node]) return false;
            
        }
        return true;

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        // we can color it with 0 / 1;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // if it is not colored
                if(bfs(graph,color,i)==false){
                    return false;
                }

                if(dfs(graph , color , i , 0) == false) return false ;
            }
        }
        return true;
    }
};