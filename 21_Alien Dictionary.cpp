// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}

// baa  
// abcd
// abca
// cab
// cad

// b apper before a in given order then {b , a}
// {abc == abc} d apper before a in given order then {b ,d , a}
// a apper before c in given order then {b ,d , a , c}
// {ca == ca} b apper before d in given order then {b ,d , a , c} already follows 

// so the correct order is {b ,d , a , c} ;


// time Complexity : O(V + E) + O(V + E)  
class Solution{
    public:
    
    vector<int> topo(vector<int> adj[] , int V){
        vector<int> indegree(V , 0);
	    for(int i =0 ;  i< V ; i ++){
	        for(auto nbrs : adj[i]){
	            indegree[nbrs] ++ ;
	        }
	    }
        
	    // insert those indegree whose indegree is zero 
	    queue<int> q ;
	    for(int i = 0 ; i< V ; i ++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    // atleast one indegree has to be inserted to start BFS using kahn algo 
	    vector<int> topoAns;
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        
	        // we push this node into topoAns because its indegree is zero 
	        topoAns.push_back(node); 
	        
	        // now we have a node whose indegree is zero 
	        // now traverse to its neighbour and reduce its indegree to zero 
	        for(auto &nbrs : adj[node]){
	            indegree[nbrs] -- ;
	            if(indegree[nbrs] == 0){
	                q.push(nbrs);
	            }
	        }
	        
	    }
	    
	    
	    return topoAns ;
    }f
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0 ; i < N - 1 ;i ++){
            string s = dict[i];
            string t = dict[i + 1];
            
            for(int j = 0 ; j < min(s.size() , t.size()) ; j ++){
                if(s[j] != t[j]){
                    adj[s[j] - 'a'].push_back(t[j] - 'a') ;
                    break;
                }
            }
        }
        
        vector<int> ans = topo(adj, K);
        string temp = "";
        for(auto x : ans){
            temp = temp + char(x + 'a');
        }
        return temp;
        
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

