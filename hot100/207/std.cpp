#include <vector>
#include <queue>

using std::queue;
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& edge : prerequisites) {
            if (edge.size() != 2) {
                continue;  // skip malformed edges
            }
            int course = edge[0];
            int prereq = edge[1];
            graph[prereq].push_back(course);
            ++indegree[course];
        }

        queue<int> ready;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) {
                ready.push(course);
            }
        }

        int completed = 0;
        while (!ready.empty()) {
            int course = ready.front();
            ready.pop();
            ++completed;

            for (int next : graph[course]) {
                if (--indegree[next] == 0) {
                    ready.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};
