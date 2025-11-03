#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<string> ans;
    void dfs(int pos, int target, int score, string now)
    {
        if(pos == target)
        {
            if(score == 0) ans.push_back(now);
            return ;
        }

        if(score + 1 <= target - pos - 1) dfs(pos + 1, target, score + 1, now + '(');
        if(score > 0) dfs(pos + 1, target, score - 1, now + ')');
    }

public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        dfs(0, 2 * n, 0, "");
        return ans;
    }
};