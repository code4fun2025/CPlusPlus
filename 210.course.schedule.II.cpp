class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses, vector<int>());
        //map each course to prereq list
        for(vector<int>& pre : prerequisites)
            preMap[pre[0]].push_back(pre[1]);

        // visited state: 0 = unknown, 1 = visiting, 2 = visited/clear
        // initialize the visited table with 0
        vector<int> visited(numCourses, 0);
        
        vector<int> orderedCourse;
        
        // check every course, in case for isolated course couse 1->2
        for(int i = 0; i < numCourses; ++i)
            if(!dfs(preMap, visited, orderedCourse, i)) return {};
        
        return orderedCourse;

    }
    
    bool dfs(vector<vector<int>>& preMap, vector<int>& visited, vector<int>& orderedCourse, int crs)
    {
        // found loop/circle, return empty array 
        if (visited[crs] == 1) 
            return false;
        // found visited/clear state, return true 
        if (visited[crs] == 2)
            return true;
        
        // mark we are visiting the course
        visited[crs] = 1;
        for(int pre: preMap[crs])
            // return if there's any prereq returns false
            if(!dfs(preMap, visited, orderedCourse, pre)) 
                return false;
        
        // no loop, mark the course to be visisted/cleared
        visited[crs] = 2;
        orderedCourse.push_back(crs);
        
        return true;
    }
};
