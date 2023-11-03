class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i=0; i<n; i++){
            for(string word: wordDict){
                int k = word.size();
                if (i< k - 1)
                    continue;
                if (i == k-1 || dp[i-k])
                    if (s.substr(i-k+1,k) == word){
                        dp[i] = true;
                        break;
                    }
            }
        }
        return dp[n-1];
    }
};