class Solution {
public:
    int ladderLength(string startWord, string endWord,vector<string>& arr) {
        queue<pair<string ,int > > q;
        unordered_set<string> st (arr.begin() , arr.end());
        q.push({startWord , 1});
        // now we pushed into the queue so we have to removed from the st 
        st.erase(startWord);


        // time -> O(N + startWordSize * 26) 
        while(!q.empty()){
            string x = q.front().first ;
            int steps = q.front().second ;
            q.pop() ;
            // basic dfs above till now 

            // at the time when we equal to endWord we stop our BFS 
            if(x == endWord){
                return steps ;
            }

            // now start changing each characher in startWord 
            for(int i = 0 ; i < x.size()  ; i ++){
                char original = x[i] ;
                for(char c = 'a' ; c <= 'z' ; c ++){
                    x[i] = c ;
                    if(st.find(x) != st.end()){
                        st.erase(x);
                        q.push({x , steps + 1});
                    }
                }
                x[i] = original ;
            }
        }
        return 0 ;

        
    }
};