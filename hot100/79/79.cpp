#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool ans;
    pair<int, int> act[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> vis;

    void dfs(int x, int y, int pos, vector<vector<char>> &board, const string &word)
    {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return ;
        if(vis[x][y]) return;
        if(word[pos] != board[x][y]) return ;
        if(pos + 1 == word.size()) { ans = 1; return ; }
        vis[x][y] = 1;

        for(int i = 0; i < 4; ++i)
        {
            dfs(x + act[i].first, y + act[i].second, pos + 1, board, word);
            if(ans) break;
        }

        vis[x][y] = 0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        ans = 0;
        vis.resize(board.size(), vector<bool>(board[0].size()));
        for(int i = 0; i < board.size(); ++i)
        {
            if(ans) break;
            for(int j = 0; j < board[i].size(); ++j)
            {
                dfs(i, j, 0, board, word);
                if(ans) break;
            }
        }

        return ans;
    }
};