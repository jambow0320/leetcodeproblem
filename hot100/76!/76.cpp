/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/

/*
一开始想的很复杂，对于每种字符维护一个链表，然后去check每种字符的左端点的位置取max
其实这种区间找左端点，完全不必要去取min取max，双指针滑动窗口就行了
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int charToint(char c)
    {
        if(c >= 'a' && c <= 'z') return c - 'a';
        else return c - 'A' + 26;
    }   

public:
    string minWindow(string s, string t) {
        vector<int> require_cnt(52);

        for(auto c : t)
            ++require_cnt[charToint(c)];

        int unsatisfy = 0;
        for(int i = 0; i < 52; ++i) 
            if(require_cnt[i] != 0)
                ++unsatisfy;
                
        vector<int> cnt(52);
        int l = 0;
        int ans = INT_MAX;
        pair<int, int> ans_lr;
        for(int r = 0; r < s.size(); ++r)
        {
            int c = charToint(s[r]);
            ++cnt[c];
            if(require_cnt[c] != 0 && cnt[c] == require_cnt[c])
                --unsatisfy;
            
            if(unsatisfy == 0)
            {
                while(l < r)
                {
                    int c = charToint(s[l]);
                    if(require_cnt[c] == 0 || cnt[c] > require_cnt[c])
                    {
                        --cnt[c];
                        ++l;
                    }
                    else break;
                }
                
                if(ans > (r - l + 1))
                {
                    ans = r - l + 1;
                    ans_lr = make_pair(l, r);
                }
            }
        }

        if(ans != INT_MAX)
            return string(s.begin() + ans_lr.first, s.begin() + ans_lr.second + 1);
        else return "";
    }
};