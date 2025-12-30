// problem: 207. Course Schedule
// difficulty: medium 
// topics: bfs, dfs, graph, topological sort
// approach: first of all make a graph (vector of vectors) of size numCourses, it will assign space to graph as the number of couses, then make a inDegree vector which will store, how many courses are to be done
// before starting a particular course at that index, idea is that - we will first make the graph and inorder vector by the prerequisites and numCourses given then we will make a queue to store the courses with 
// currently zero number of prerequisites, so initially if there are any such course we will store it in queue then we will assign a variable named completed to store the number of courses which are completed 
// then we will run a loop while our queue is not empty, and in that, we will first pop the front element of queue and store it in a variable named curr, then we will increase completed by one since one pop = one 
// course completed, then we will again run a loop inside, which will decrease the inorder value of the courses whose prerequisites were the course which we completed, and if inorder of any couse becomes zero, we 
// will just push it to the queue and the while loop will keep running until our queue becomes empty (means either no more courses possible, or all r done), after coming out of loop we will return the comparison
// of completed and numCourses, if both are same we will get true else false.
// time: O(V+E), because we are going through all preq and also all courses which becomes edge+nodes 
// space: O(V+E)
// link: https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto& p : prerequisites)
        {
            int course = p[0];
            int preq = p[1];
            graph[preq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }

        int completed = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            completed++;
            for(int next : graph[curr])
            {
                inDegree[next]--;
                if(inDegree[next]==0)
                q.push(next);
            }
        }
        return completed == numCourses;
    }
};

