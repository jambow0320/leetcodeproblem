#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using std::vector;
using std::string;
using std::unordered_map;
using std::pair;

class Solution {
private:
    unordered_map<string, int> id;
    vector<vector<pair<int, double>>> edge;
    vector<bool> vis;
    int tot = 0;
    double ans = 0;

    int var_insert(string u)
    {
        auto it = id.find(u);
        if(it == id.end())
        {
            id[u] = tot++;
            return tot - 1;
        }
        return it->second;
    }

    void addEdge(int u, int v, double value)
    {
        edge[u].push_back(std::make_pair(v, value));
    }

    void dfs(int u, int goal, double now)
    {
        vis[u] = true;
        if(u == goal) 
        {
            ans = now;
            return ;
        }
        for(auto x : edge[u])
            if(!vis[x.first])
                dfs(x.first, goal, now * x.second);
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        tot = 0; id.clear(); edge.clear();
        edge.resize(40);

        for(int i = 0; i < equations.size(); ++i)
        {
            int u = var_insert(equations[i][0]); 
            int v = var_insert(equations[i][1]);
            addEdge(u, v, values[i]);
            addEdge(v, u, 1 / values[i]);
        }

        vis.clear();
        vis.resize(tot);
        vector<double> Ans;
        for(auto q : queries)
        {
            ans = -1;
            if(id.count(q[0]) && id.count(q[1]))
            {
                vis.assign(tot, false);
                dfs(id[q[0]], id[q[1]], 1);
            }
            Ans.push_back(ans);
        }

        return Ans;
    }
};