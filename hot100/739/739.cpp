#include <vector>
#include <stack>

using std::vector;
using std::stack;
using std::pair;
using std::make_pair;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > sta;
        vector<int> ans(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i)
        {
            int x = temperatures[i];
            while(!sta.empty() && sta.top().first < x)
            {
                ans[sta.top().second] = i - sta.top().second;
                sta.pop();
            }
            sta.push(make_pair(x, i));
        }
        return ans;
    }
};

int main()
{
    return 0;
}