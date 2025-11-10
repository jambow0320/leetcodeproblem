#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> prefix(s.size());
        prefix[0] = ((s[0] == '(') ? 1 : -1);
        for(int i = 1; i < s.size(); ++i)
            prefix[i] = prefix[i - 1] + ((s[0] == '(') ? 1 : -1);
        
        for()
    }
};