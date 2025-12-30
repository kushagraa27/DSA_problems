// problem: 200. Number of Islands
// difficulty: medium
// topics: array, dfs, bfs, union find, matrix 
// approach: so as a first graph problem, approach will be detailed, first of all we choose dfs for this problem since its easier (suggested by gpt) then we will assign number of rows to rows variable and number of 
// columns to our cols variable and initialise islands as zero, then we will iterate through each cell in our grid using loops, and if we found any '1' we will first of all increase islands by one then pass the grid,
// that row and column to the function named dfs, which will make all '1's at top surrounding that '1', '0' including that '1' so that we dont count same island again, this will be achieved by dfs, recursion 
// code below shows how to do it. finally return the islands.
// time: O(RxC)
// space: O(RxC)
// link: https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands =0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>> &grid, int r, int c)
    {   
        int row = grid.size();
        int col = grid[0].size();
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]=='0')
        return;

        grid[r][c] = '0';

        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
};

