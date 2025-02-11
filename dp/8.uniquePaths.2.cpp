// Unique paths
// You are given an m x n integer array grid. 
// There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. 
// A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N*M)
// space complexity o(N*M) -> auxillary space
int helper(vector<vector<int>> &obstacleGrid, int n, int m, int x, int y){
    // if there is 1 then it is obstacles
    if(x == n || y == m || obstacleGrid[x][y] == 1) return 0;
    if(x == n-1 && y == m-1) return 1;

    // moving to the right
    int rightMove = helper(obstacleGrid, n, m, x, y+1);
    int downMove = helper(obstacleGrid, n, m, x+1, y);
    return rightMove + downMove;
}

int noOfUniquePaths(vector<vector<int>>& obstacleGrid){
    if(obstacleGrid[0][0] == 1) return 0;
    return helper(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), 0, 0);
}


// time complexity o(2^N*M)
// space complexity o(M*N)
int helper(vector<vector<int>> &obstacleGrid, int n, int m, int x, int y, vector<vector<int>> &memo){
    // if there is 1 then it is obstacles
    if(x == n || y == m || obstacleGrid[x][y] == 1) return 0;
    if(x == n-1 && y == m-1) return memo[x][y] = 1;
    if(memo[x][y] != -1) return memo[x][y];

    // moving to the right
    int rightMove = helper(obstacleGrid, n, m, x, y+1, memo);
    int downMove = helper(obstacleGrid, n, m, x+1, y, memo);
    return memo[x][y] = rightMove + downMove;
}

int noOfUniquePaths(vector<vector<int>>& obstacleGrid){
    if(obstacleGrid[0][0] == 1) return 0;
    vector<vector<int>> memo(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    return helper(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), 0, 0, memo);
}