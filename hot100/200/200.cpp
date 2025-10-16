// dfs就可以了，没必要并查集

#include <vector>
#include <algorithm>

using std::vector;

//using namespace std;
//#include <iostream>

class UnionFind
{
public:
    UnionFind(size_t n) : father(n), size(n, 1)
    {
        for(int i = 0; i < n; ++i)
            father[i] = i;
    }

    int find(int x)
    {
        return (father[x] == x) ? x : (father[x] = find(father[x]));
    }

    void unite(int x, int y)
    {
        //cout << x << ' ' << y << endl;
        x = find(x);
        y = find(y);
        if(x != y)
        {
            if(size[x] < size[y]) std::swap(x, y);
            father[y] = x;
            size[x] += size[y];
        }
    }
    
    int count(vector<vector<char> >& grid)
    {
        int idx = 0, cnt = 0;
        size_t m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    cnt += (idx == find(idx));
                }
                ++idx;
            }
        return cnt;
    }

private:
    vector<int> father;
    vector<int> size;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        //cout << m << ' ' << n << endl;
        UnionFind dsu(m * n);

        int idx = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    if(i && grid[i - 1][j] == '1') dsu.unite(idx, (i - 1) * n + j);
                    if(j && grid[i][j - 1] == '1') dsu.unite(idx, i * n + j - 1);
                }
                ++idx;
            }

        return dsu.count(grid);
    }
}sol;

int main()
{
    vector<vector<char> > grid(2, vector<char>("01", "01" + 2));
    //cout << sol.numIslands(grid) << endl;
    return 0;
}