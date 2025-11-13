#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        stack<char> sta;

        for(auto c : s)
        {
            if(c == ')') 
            {
                if(sta.empty()) return false;
                else
                {
                    if(sta.top() != '(') return false;
                    sta.pop();
                }
            }
            else if(c == ']')
            {
                if(sta.empty()) return false;
                else
                {
                    if(sta.top() != '[') return false;
                    sta.pop();
                }
            }
            else if(c == '}')
            {
                if(sta.empty()) return false;
                else
                {
                    if(sta.top() != '{') return false;
                    sta.pop();
                }
            }
            else sta.push(c);
        }

        if(sta.empty())
            return true;
        else return false;
    }
};