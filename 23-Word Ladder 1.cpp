class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q; 
        unordered_set<string>mp(wordList.begin(),wordList.end()); 
        q.push({startWord,1}); 
        mp.erase(startWord); 
        while(!q.empty()) 
        {
            string word=q.front().first; 
            int step=q.front().second; 
            q.pop(); 
            if(word==targetWord) return step; 
            for(int i=0;i<word.length();i++) 
            {
                char orginal=word[i]; 
                for(char c='a' ; c<='z';c++) 
                {
                    word[i]=c; 
                    if(mp.find(word)!=mp.end()) 
                    {
                        q.push({word,step+1}); 
                        mp.erase(word); 
                    }
                }
                word[i]=orginal; 
            }
        }
        return 0; 
    }
};
