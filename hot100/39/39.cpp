#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> ans;

    void dfs(const vector<int> &candidates, vector<int> now, int pos, int score)
    {
        if(pos == candidates.size())
        {
            if(score == 0) ans.push_back(now);
            return ;
        }

        for(int i = 0; candidates[pos] * i <= score; ++i)
        {
            dfs(candidates, now, pos + 1, score - candidates[pos] * i);
            now.push_back(candidates[pos]);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, vector<int>(), 0, target);
        return ans;
    }
};