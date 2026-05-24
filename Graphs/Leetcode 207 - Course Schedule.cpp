// Problem Link: https://leetcode.com/problems/course-schedule
// Time Complexity: O(V + E)

class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, int node){
        visited[node] = true;
        recStack[node] = true;;

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(isCycle(adj, visited, recStack, neighbour)) return true;
            }
            else if(recStack[neighbour]) return true;
        }

        recStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& preReqs) {
        vector<vector<int>> adj(numCourses);
        for(auto& e : preReqs) adj[e[1]].push_back(e[0]);

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCycle(adj, visited, recStack, i)) return false;
            }
        }

        return true;
    }
};
