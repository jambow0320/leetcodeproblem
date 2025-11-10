/*
寻找合法括号子串的最长长度
*/

/*
我是用单调栈加二分做的，这样是nlogn的，也就是维护一个prefix前缀和，然后从后往前扫，维护一个单调栈，然后对于每个位置，找他前缀和与单调栈里匹配的
我一开始是拿二分去找，但是其实不用，因为你要找的位置是与当前prefix完全相等的(因为这个栈里的元素前后变化只有正负一，所以其实是连续的，所以对于单调栈进来一个相等的元素，应该忽略它，因为要保留最远的)，
所以不是找大于等于的位置，而是找相等的用个桶来维护就可以了
这样就是O(n)
*/

/*
dp做法，设dp[i]表示以i结尾的最长合法长度
我们对于所有')'的位置，进行更新，先检查它前面的如果是'('，那刚好是凑一对()，dp[i] <- dp[i - 2] + 2
前面如果是')'，也就是'))'的形式，检查i - dp[i - 1] - 2是不是'('，是的话，就是"(dp[i-1])"的形式，dp[i] <- dp[i-1] + 2 + dp[i - dp[i - 1] - 2]
*/

/*
简单栈做法，核心思想是，维护一个最近未被匹配的')'括号位置记为p，如果后续有合法的序列，那可以是以p之后的连续某个'('括号开头
比如")(((("，可以的合法序列都是以')'后的这四个((((之一为开头的
然后从前往后扫，维护一个栈存未被匹配的'('，每次进来')'都把栈顶做匹配，并更新答案，当栈只剩一个被匹配走了此时恰好空了,那可以更新为now-p，就类似)()()这种情况，最长长度是4
实际处理时，我们会默认往栈最底下放一个右括号的坐标(就是最近未被匹配的')')
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
*/

/*
空间O(1)做法
贪心，维护left,right表示当前左右括号的个数，从前往后扫，当left==right就更新一次答案，当right>left就两者都清零重来
但是这种做法会有漏掉的情况，也就是(((())，这种左括号始终大于右括号的情况
不难发现这种情况，只会出现在结尾的某一段，那我们从后再往前扫一遍，这次我们的逻辑反过来，因为从后往前看，右括号就变成左括号了，left>right再清零
*/

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;

using namespace std;

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;

        vector<int> prefix(s.size());
        prefix[0] = ((s[0] == '(') ? 1 : -1);
        for(int i = 1; i < s.size(); ++i)
            prefix[i] = prefix[i - 1] + ((s[i] == '(') ? 1 : -1);
        
        vector<pair<int, int>> sta;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            int x = prefix[i];
            while(!sta.empty())
            {
                if(x < sta[sta.size() - 1].first) sta.pop_back();
                else break;
            }
            if(sta.empty() || sta[sta.size() - 1].first != x) sta.push_back(std::make_pair(x, i));

            int pre = i ? prefix[i - 1] : 0;

            auto pos = std::lower_bound(sta.begin(), sta.end(), std::make_pair(pre, i));
            if(pos == sta.end()) continue;
            if(pos->first != pre) continue;
            ans = std::max(ans, (pos->second) - i + 1);
            //cout << i << ' ' << pos->second << endl;
        }

        return ans;
    }
};*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;

        vector<int> prefix(s.size());
        prefix[0] = ((s[0] == '(') ? 1 : -1);
        for(int i = 1; i < s.size(); ++i)
            prefix[i] = prefix[i - 1] + ((s[i] == '(') ? 1 : -1);
        
        vector<pair<int, int>> sta;
        vector<int> cnt(s.size() * 2 + 1, -1);
        int cnt_bias = s.size();
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            int x = prefix[i];
            while(!sta.empty())
            {
                if(x < sta[sta.size() - 1].first) 
                {
                    cnt[cnt_bias + sta[sta.size() - 1].first] = -1;
                    sta.pop_back();
                }
                else break;
            }
            if(sta.empty() || sta[sta.size() - 1].first != x) 
            {
                sta.push_back(std::make_pair(x, i));
                cnt[cnt_bias + x] = i;
            }

            int pre = i ? prefix[i - 1] : 0;

            /*
            auto pos = std::lower_bound(sta.begin(), sta.end(), std::make_pair(pre, i));
            if(pos == sta.end()) continue;
            if(pos->first != pre) continue;
            ans = std::max(ans, (pos->second) - i + 1);*/
            if(cnt[cnt_bias + pre] != -1)
                ans = std::max(ans, cnt[cnt_bias + pre] - i + 1);
        }

        return ans;
    }
};

Solution s;

int main()
{
    s.longestValidParentheses("(()");
    return 0;
}