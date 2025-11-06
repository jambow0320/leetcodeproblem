#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> ans;

    void dfs(vector<int> now, const vector<int> &nums, int pos)
    {
        if(pos == nums.size())
        {
            ans.push_back(now);
            return ;
        }

        int x = nums[pos];
        for(int i = 0; i < now.size(); ++i)
        {
            vector<int> tmp(now);
            tmp.insert(tmp.begin() + i, x);
            dfs(tmp, nums, pos + 1);
        }
        now.push_back(x);
        dfs(now, nums, pos + 1);
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> now;
        dfs(now, nums, 0);
        return ans;
    }
};