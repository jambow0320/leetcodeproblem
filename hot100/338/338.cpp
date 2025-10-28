#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        int tot = 1;
        ans.push_back(0);
        while(1)
        {
            for(int i = 0; i < tot; ++i)
                ans.push_back(ans[i] + 1);
            tot <<= 1;
            if(tot > n) break;
        }

        return vector<int>(ans.begin(), ans.begin() + n + 1);
    }
};