#include <vector>
#include <queue>

using std::queue;
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const auto& edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            ++indegree[v];
        }

        queue<int> ready;
        for(int i = 0; i < numCourses; ++i)
        {
            if(!indegree[i]) ready.push(i);
        }

        int completed = 0;
        while(!ready.empty())
        {
            int u = ready.front();
            ready.pop();
            ++completed;

            for(auto v : graph[u])
            {
                --indegree[v];
                if(!indegree[v]) ready.push(v);
            }
        }

        return (completed == numCourses);
    }
};

int main() {}