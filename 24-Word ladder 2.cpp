//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
    vector<string>& wordList) {
        unordered_set<string>mp(wordList.begin(),wordList.end()); 
        queue<vector<string>>q; 
        q.push({beginWord}); 
        vector<string>UsedOnLevel; 
        UsedOnLevel.push_back(beginWord); 
        int level=0; 
        vector<vector<string>>ans; 
        while(!q.empty()) 
        {
            vector<string>vec=q.front(); 
            q.pop(); 
            if(vec.size()>level) 
            {
                level++; 
                for(auto it:UsedOnLevel) mp.erase(it); 
            }
            string word=vec.back(); 
            if(word==endWord) {
                if(ans.size()==0) ans.push_back(vec); 
                else if(ans[0].size()==vec.size()) 
                    ans.push_back(vec); 
            }
            
            for(int i=0;i<word.length();i++) 
            {
                char j=word[i];
                for(int c='a';c<='z';c++) 
                {
                    word[i]=c; 
                    if(mp.find(word)!=mp.end()) 
                    {
                        vec.push_back(word); 
                        q.push(vec);  
                        UsedOnLevel.push_back(word); 
                        vec.pop_back(); 
                    }
                }
                word[i]=j; 
            }
        }
        return ans; 
    }
};
