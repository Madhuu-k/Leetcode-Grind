// Problem Link: https://leetcode.com/problems/course-schedule-iii/
// Time Complexity: o(n log n)

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        priority_queue<int> maxHeap;
        int time = 0;
        for(auto& c : courses){
            time += c[0];
            maxHeap.push(c[0]);
            if(time > c[1]){
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};