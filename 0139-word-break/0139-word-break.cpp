class Solution {
public:
    bool dp(string s, int i, vector<string>& words, vector<int>& memo){
        if (i<0)
            return true;
        if (memo[i] != -1)
            return memo[i] == 1;
        for (string word: words){
            int k = word.size();
            if (i-k+1 < 0)
                continue;
            if (s.substr(i-k+1, k) == word && dp(s, i-k, words, memo)){
                memo[i] = 1;
                return true;
            }
        
        }
        memo[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> memo(n, -1);
        return dp(s, n-1, wordDict, memo);
    }
};