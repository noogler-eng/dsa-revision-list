// Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

#include<iostream>
#include<vector>
using namespace std;

int helper(vector<vector<int>> &grid, int x, int y){
    // as due to min we cant return 0 instead that INT_MAX
    if(x < 0 || y < 0) return INT_MAX;
    if(x == 0 && y == 0) return grid[0][0];

    // moving up
    int movingUp = grid[x][y] + helper(grid, x-1, y);
    // moving left
    int movingLeft = grid[x][y] + helper(grid, x, y-1);
    return min(movingUp, movingLeft);
}

int minPathSum(vector<vector<int>>& grid) {
    return helper(grid, grid.size()-1, grid[0].size()-1);
}


// optmized approach
int helper(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &memo){
    // as due to min we cant return 0 instead that INT_MAX
    if(x < 0 || y < 0) return INT_MAX;
    if(x == 0 && y == 0) return memo[x][y] = grid[0][0];
    if(memo[x][y] != -1) return memo[x][y];

    // moving up
    int movingUp = grid[x][y] + helper(grid, x-1, y, memo);
    // moving left
    int movingLeft = grid[x][y] + helper(grid, x, y-1, memo);
    return memo[x][y] = min(movingUp, movingLeft);
}

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
    return helper(grid, grid.size()-1, grid[0].size()-1, memo);
}

