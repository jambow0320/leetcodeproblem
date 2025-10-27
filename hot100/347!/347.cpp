// 把次数拿个map统计一下，然后再对于次数跑快排就行了，找第k大和前k大是一样的

#include <vector>
#include <utility>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using std::vector;
using std::pair;
using std::unordered_map;

class Solution {
private:
    unordered_map<int, int> cnt;

    void ksort(vector<pair<int, int>> &seq, int l, int r, int k)
    {
        int picked = std::rand() % (r - l + 1) + l;
        swap(seq[l], seq[picked]);

        int pivot = seq[l].second;
        int index = l;
        for(int i = l + 1; i <= r; ++i)
        {
            if(seq[i].second >= pivot)
            {
                swap(seq[index + 1], seq[i]);
                ++index;
            }
        }
        swap(seq[l], seq[index]);

        if(k <= index - l)
        {
            ksort(seq, l, index - 1, k);
        }
        else
        {
            if(k > index - l + 1)
                ksort(seq, index + 1, r, k - (index - l + 1));
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::srand(time(0));

        for(auto x : nums)
            ++cnt[x];

        vector<pair<int, int>> seq;
        for(auto x : cnt)
            seq.push_back(x);

        ksort(seq, 0, seq.size() - 1, k);

        vector<int> ans;
        for(int i = 0; i < k; ++i)
            ans.push_back(seq[i].first);

        return ans;
    }
};