class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wset(wordDict.begin(), wordDict.end());
        queue<int> q; q.push(0);
        vector<bool> vis(n, false);
        while(!q.empty()){
            int st = q.front(); q.pop();
            if (st == n)
                return true;
            for(int x = st+1; x <= n; x++){
                if (vis[x])
                    continue;
                if (wset.find(s.substr(st, x-st)) != wset.end()){
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        return false;
    }
};