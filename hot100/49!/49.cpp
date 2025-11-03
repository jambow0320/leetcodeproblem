// 写一个hash去哈希字母出现次数就行，注意cnt.clear()是清空所有元素

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
private:
    struct VectorHash
    {
        std::size_t operator() (const std::vector<int> &v) const
        {
            std::size_t seed = 0;
            for(int x : v)
                seed ^= std::hash<int>{}(x) + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> cnt(26);
        unordered_map<vector<int>, vector<string>, VectorHash> mp;
        for(const auto &s : strs)
        {
            std::fill(cnt.begin(), cnt.end(), 0);
            for(auto c : s)
                ++cnt[c - 'a'];
            mp[cnt].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto &x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};