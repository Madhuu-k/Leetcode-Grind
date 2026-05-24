// Problem Link: https://leetcode.com/problems/course-schedule-ii/
// Time Complexity: O(V + E)

class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack,
    vector<int>& result, int node){
        visited[node] = true;
        recStack[node] = true;

        bool cycle = false;

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(isCycle(adj, visited, recStack, result, neighbour)) return true;
            }
            else if(recStack[neighbour]) return true;
        }

        recStack[node] = false;
        result.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& preReq) {

        vector<vector<int>> adj(numCourses);
        for(auto& e : preReq) adj[e[1]].push_back(e[0]);

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        vector<int> result;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCycle(adj, visited, recStack, result, i)){
                    return {};
                }
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
