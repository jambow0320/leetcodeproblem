#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<string> alphabet;
    vector<string> ans;

    void dfs(int pos, string tmp, const string &digits)
    {
        if(pos == digits.size())
        {
            ans.push_back(tmp);
            return ;
        }

        int fg = digits[pos] - '0';
        for(auto c : alphabet[fg])
            dfs(pos + 1, tmp + c, digits);
    }

public:
    vector<string> letterCombinations(string digits) {
        alphabet.resize(11);
        alphabet[2] = "abc";
        alphabet[3] = "def";
        alphabet[4] = "ghi";
        alphabet[5] = "jkl";
        alphabet[6] = "mno";
        alphabet[7] = "pqrs";
        alphabet[8] = "tuv";
        alphabet[9] = "wxyz";

        dfs(0, "", digits);

        return ans;
    }
};