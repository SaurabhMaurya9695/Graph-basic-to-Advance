// this approach is correct but this will take (n * (n * log(n)) ) ;
// this will give us TLE 
// for accepted within in range of 10^5 we have to submitted in logn complexity or lesser 


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size() ;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        pq.push({start , 0}) ;
        
        while(!pq.empty()){
            auto top = pq.top() ;
            pq.pop();
            int node  = top.first;
            int steps = top.second ;
            
            if(node == end){
                return steps ;
            }
            
            for(int i = 0 ; i < arr.size() ; i ++){
                int val = node * arr[i] ;
                if(val > 100000){
                    val %= 100000 ;
                }
                if(val == end){
                    return steps + 1;
                }
                else{
                    pq.push({val , steps + 1});
                }
            }
            
        }
        
        return -1;
        
    }
};


````````````````````````````````````````````````````````````````````````````````````````````


// optimize code ;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size() ;
        
        queue<pair<int,int>> q;
        q.push({start , 0}) ;
        vector<int> dist(100000, 1e9);
        dist[start] = 0 ;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop() ;
            int node  = it.first ;
            int steps = it.second;
            
            if(start == end){
               return steps;
            }
            
            for(auto x : arr){
                int total = (x * node) % 100000 ;
                if(steps + 1 < dist[total]){
                    dist[total] = steps + 1;
                    if(total == end){
                        return steps + 1;
                    }
                    q.push({total , steps + 1});
                }
            }
            
        }
        
        return -1;
        
    }
};
