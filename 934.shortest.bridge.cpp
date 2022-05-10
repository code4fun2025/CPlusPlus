class Solution {
public:
    /*  DFS
            #1. return directly if it's out of bounds or not land node
            #2. mark land node to be visited and add to the queue
            #3. for all 4 directions, further DFS
        BFS
            #1. for each element in the queue, pop out element
            #2. for all 4 directions, continue if out of bound or visted node, if we find another unvisited land node, return steps
            #3. Mark visited and add to queue   */
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0; i< grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j)
                if (grid[i][j])
                {
                    dfs(grid, i, j, q);
                    return bfs(grid, i, j, q);
                }
        return -1;
    }
private:
    void dfs(vector<vector<int>>& A, int r, int c, queue<pair<int, int>>& q) {
        //  return directly if it's out of bounds or not land node
        if (r < 0 || c < 0 || r >= A.size() || c >= A[0].size() || A[r][c] != 1)
            return;
        //   #2. mark land node to be visited and add to the queue
        A[r][c] = 2;
        q.emplace(r, c);
        //   for all 4 directions, further DFS
        dfs(A, r - 1, c, q);
        dfs(A, r + 1, c, q);
        dfs(A, r, c - 1, q);
        dfs(A, r, c + 1, q);
    }
    
    int bfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q) {
        int steps = 0;
        while (!q.empty()) {
            size_t size = q.size();
            while (size --) {
                //#1. for each element in the queue, pop out element                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                //#2. for all 4 directions, continue if out of bound or visted node, if we find another unvisited land node, return steps
                vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0, -1}};
                for(auto d : directions)
                {
                    int r = x + d.first;
                    int c = y + d.second;
                    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 2)
                        continue;
                    
                    // if we find another unvisited land node, return steps
                    if (grid[r][c] == 1)  
                        return steps;
                    
                    // #3. Mark visited and add to queue 
                    grid[r][c] = 2;
                    q.emplace(r, c);                       
                }
            }
            ++steps; // initial queue is done, which means one level is done, add a step
        }
        return -1;
    }
};
